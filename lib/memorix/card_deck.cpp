#include "card_deck.h"

namespace memorix {

void CardDeck::next() {
    if (current_card_ == cards_.size() - 1) {
        current_card_ = 0;
        return;
    }

    current_card_++;
}

void CardDeck::previous() {
    if (current_card_ == 0) {
        current_card_ = cards_.size() - 1;
        return;
    }

    current_card_--;
}

const Card& CardDeck::current() const {
    return cards_[current_card_];
}

}  // namespace memorix
