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

const CardViewWay CardDeck::viewWay() const {
    return view_way_;
}

void CardDeck::setCardViewWay(CardViewWay view_way) {
    view_way_ = view_way;
}

const std::string_view CardDeck::current() const {
    const Card& card = cards_[current_card_];

    switch (view_way_) {
        case CardViewWay::FRONT:
            return card.front;
        case CardViewWay::BACK:
            return card.back;
    }
}

}  // namespace memorix
