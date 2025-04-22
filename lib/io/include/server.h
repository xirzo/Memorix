#ifndef SERVER_H
#define SERVER_H

#include <atomic>
#include <condition_variable>
#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <string_view>

#include "crow.h"
#include "io.h"

namespace io {

class Server : public memorix::IO
{
public:
    explicit Server(std::size_t port = 5000);
    ~Server() override;

    void setInputCallback(std::function<void(memorix::InputType)> callback) override;

    void startListening() override;
    void stopListening() override;

    void output(std::string_view text) const override;

private:
    void setupRoutes();
    void processInputQueue();

private:
    std::unique_ptr<crow::SimpleApp> app_;
    std::thread server_thread_;
    std::size_t port_;
    std::atomic<bool> is_listening_;
    std::thread input_processing_thread_;

    inline static std::queue<memorix::InputType> input_queue_;
    inline static std::mutex input_mutex_;
    inline static std::condition_variable input_cv_;

    mutable std::string current_output_;
    mutable std::mutex output_mutex_;
    mutable std::condition_variable output_cv_;
    mutable int output_version_;

    std::function<void(memorix::InputType)> input_callback_;
};

};  // namespace io

#endif  // !SERVER_H
