#include "app.h"

#include <exception>
#include <iostream>
#include <memory>

namespace memorix {

App::App(std::unique_ptr<FileReader> file_reader)
    : is_running_(true), file_reader_(std::move(file_reader)) {
    try {
        cards_ = file_reader_->tryRead();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}

bool App::isRunning() const {
    return is_running_;
}

void App::update() {}

}  // namespace memorix
