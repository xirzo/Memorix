#include "app.h"

#include <exception>
#include <iostream>
#include <memory>

#include "card_deck.h"

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
    std::cout << deck_->current() << std::endl;

    if (io_->hasInput() == false) {
        return;
    }

    switch (io_->getInput()) {
        case InputType::UNKNOWN: {
            std::cout << "Unknown input" << std::endl;
            return;
        }
        case InputType::NEXT_CARD: {
            deck_->next();
            break;
        }
        case InputType::PREVIOUS_CARD: {
            deck_->previous();
            break;
        }
        case InputType::FLIP_CARD: {
            CardViewWay view_way = deck_->viewWay();

            switch (view_way) {
                case CardViewWay::FRONT:
                    view_way = CardViewWay::BACK;
                    break;
                case CardViewWay::BACK:
                    view_way = CardViewWay::FRONT;
                    break;
            }

            deck_->setCardViewWay(view_way);
            break;
        }
        case InputType::QUIT: {
            is_running_ = false;
            return;
        }
    }
}

}  // namespace memorix
