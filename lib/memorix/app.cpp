#include "app.h"

#include <memory>

namespace memorix {

App::App(std::unique_ptr<FileReader> file_reader)
    : is_running_(true), file_reader_(std::move(file_reader)) {}

bool App::isRunning() const {
    return is_running_;
}

void App::update() {
    file_reader_->tryRead();
}

}  // namespace memorix
