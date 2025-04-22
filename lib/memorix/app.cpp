#include "app.h"

#include <exception>
#include <iostream>
#include <memory>

namespace memorix {

App::App(std::unique_ptr<FileReader> file_reader, std::unique_ptr<IO> io)
    : is_running_(true), file_reader_(std::move(file_reader)), io_(std::move(io)) {
    try {
        cards_ = file_reader_->tryRead();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}

bool App::isRunning() const {
    return is_running_;
}

void App::update() {
    if (io_->hasInput() == false) {
        return;
    }

    switch (io_->getInput()) {
        case InputType::EMPTY:
            std::cout << "Empty input" << std::endl;
            break;
        case InputType::UNKNOWN:
            std::cout << "Used unknown input" << std::endl;
            break;
        case InputType::NEXT_CARD:
            std::cout << "Moved to next card" << std::endl;
            break;
        case InputType::PREVIOUS_CARD:
            std::cout << "Moved to previous card" << std::endl;
            break;
    }
}

}  // namespace memorix
