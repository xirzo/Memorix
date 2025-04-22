#include "app.h"

#include <exception>
#include <functional>
#include <iostream>
#include <memory>

#include "card_deck.h"

namespace memorix {

App::App(std::unique_ptr<FileReader> file_reader, std::unique_ptr<IO> io)
    : is_running_(false), file_reader_(std::move(file_reader)), io_(std::move(io)) {
    try {
        deck_ = std::make_unique<CardDeck>(file_reader_->tryRead());

        io_->setInputCallback([this](InputType input) { handleInput(input); });
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw;
    }
}

App::~App() {
    stop();
}

void App::run() {
    is_running_ = true;

    updateDisplay();

    io_->startListening();
}

void App::stop() {
    if (is_running_) {
        is_running_ = false;
        io_->stopListening();
    }
}

void App::updateDisplay() {
    io_->output(deck_->current());
}

void App::handleInput(InputType input) {
    try {
        switch (input) {
            case InputType::UNKNOWN: {
                std::cout << "Unknown input: Quiting..." << std::endl;
                stop();
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
                stop();
                return;
            }
        }

        updateDisplay();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        stop();
    }
}

}  // namespace memorix
