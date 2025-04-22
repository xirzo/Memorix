#include "app.h"

#include <exception>
#include <iostream>
#include <memory>

namespace memorix {

App::App(std::unique_ptr<FileReader> file_reader, std::unique_ptr<IO> io)
    : is_running_(true), file_reader_(std::move(file_reader)), io_(std::move(io)) {
    try {
        deck_ = std::make_unique<CardDeck>(file_reader_->tryRead());
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
            return;
        case InputType::UNKNOWN:
            std::cout << "Unknown input" << std::endl;
            return;
        case InputType::NEXT_CARD:
            deck_->next();
            break;
        case InputType::PREVIOUS_CARD:
            deck_->previous();
            break;
    }

    std::cout << deck_->current().front << " --- " << deck_->current().back << std::endl;
}

}  // namespace memorix
