#include "server.h"

#include <chrono>

namespace io {

Server::Server(std::size_t port)
    : app_(std::make_unique<crow::SimpleApp>()),
      port_(port),
      is_listening_(false),
      output_version_(0) {
    setupRoutes();
}

Server::~Server() {
    stopListening();

    if (server_thread_.joinable()) {
        server_thread_.join();
    }
}

void Server::setInputCallback(std::function<void(memorix::InputType)> callback) {
    input_callback_ = std::move(callback);
}

void Server::startListening() {
    if (is_listening_) return;

    server_thread_ = std::thread([this]() { app_->port(port_).multithreaded().run(); });

    is_listening_ = true;

    input_processing_thread_ = std::thread([this]() { processInputQueue(); });
}

void Server::stopListening() {
    is_listening_ = false;
    app_->stop();

    input_cv_.notify_all();
    output_cv_.notify_all();

    if (input_processing_thread_.joinable()) {
        input_processing_thread_.join();
    }
}

void Server::processInputQueue() {
    while (is_listening_) {
        memorix::InputType input;

        {
            std::unique_lock<std::mutex> lock(input_mutex_);
            input_cv_.wait(lock,
                           [this]() { return !input_queue_.empty() || !is_listening_; });

            if (!is_listening_) break;

            input = input_queue_.front();
            input_queue_.pop();
        }

        if (input_callback_) {
            input_callback_(input);
        }
    }
}

void Server::setupRoutes() {
    crow::Crow<>& app = *app_;

    CROW_ROUTE(app, "/api/command")
        .methods(crow::HTTPMethod::POST)([](const crow::request& req) {
            auto js = crow::json::load(req.body);

            if (!js || !js.has("cmd")) {
                return crow::response(400);
            }

            std::string c = js["cmd"].s();

            memorix::InputType it = memorix::InputType::UNKNOWN;
            if (c == "n")
                it = memorix::InputType::NEXT_CARD;
            else if (c == "p")
                it = memorix::InputType::PREVIOUS_CARD;
            else if (c == "f")
                it = memorix::InputType::FLIP_CARD;
            else if (c == "q")
                it = memorix::InputType::QUIT;

            {
                std::lock_guard<std::mutex> lk(input_mutex_);
                input_queue_.push(it);
            }

            input_cv_.notify_one();
            return crow::response(200);
        });

    CROW_ROUTE(app, "/api/output")
    ([this](const crow::request& req) {
        int client_version = 0;
        if (req.url_params.get("version") != nullptr) {
            client_version = std::stoi(req.url_params.get("version"));
        }

        std::unique_lock<std::mutex> lock(output_mutex_);

        bool got_new_data =
            output_cv_.wait_for(lock, std::chrono::seconds(30), [this, client_version]() {
                return output_version_ > client_version || !is_listening_;
            });

        if (!is_listening_) {
            return crow::response(503, "Server shutting down");
        }

        if (!got_new_data) {
            return crow::response(204);
        }

        crow::json::wvalue js;
        js["text"] = current_output_;
        js["version"] = output_version_;

        return crow::response(js);
    });

    CROW_ROUTE(app, "/")
    ([]() {
        return R"html(
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Memorix Web UI</title>
  </head>
  <body>
    <h1>Memorix Web UI</h1>

    <button onclick="fetch('/api/command', {
      method: 'POST',
      headers: {'Content-Type':'application/json'},
      body: JSON.stringify({cmd:'n'})
    })">Next</button>

    <button onclick="fetch('/api/command', {
      method: 'POST',
      headers: {'Content-Type':'application/json'},
      body: JSON.stringify({cmd:'p'})
    })">Prev</button>
        
    <button onclick="fetch('/api/command', {
      method: 'POST',
      headers: {'Content-Type':'application/json'},
      body: JSON.stringify({cmd:'f'})
    })">Flip</button>

    <button onclick="fetch('/api/command', {
      method: 'POST',
      headers: {'Content-Type':'application/json'},
      body: JSON.stringify({cmd:'q'})
    })">Quit</button>

    <pre id="out"></pre>
    <script>
      let currentVersion = 0;
      
      async function longPoll() {
        try {
          const response = await fetch(`/api/output?version=${currentVersion}`);
          
          if (response.status === 200) {
            const data = await response.json();
            document.getElementById('out').textContent = data.text + '\n';
            currentVersion = data.version;
          }
          
          setTimeout(longPoll, 0);
        } catch (err) {
          console.error("Error in long polling:", err);
          setTimeout(longPoll, 5000);
        }
      }
      
      longPoll();
    </script>
  </body>
</html>
)html";
    });
}

void Server::output(std::string_view text) const {
    std::lock_guard<std::mutex> lock(output_mutex_);
    current_output_ = text;
    output_version_++;
    output_cv_.notify_all();
}

}  // namespace io
