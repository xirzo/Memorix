#ifndef CARD_DECK_H
#define CARD_DECK_H

#include <vector>

#include "card.h"
namespace memorix {

class CardDeck
{
public:
    explicit CardDeck(std::vector<Card> cards)
        : cards_(std::move(cards)), current_card_(0) {}

    void next();
    void previous();
    const Card& current() const;

private:
    std::vector<Card> cards_;
    std::size_t current_card_;
};

}  // namespace memorix

#endif  // !CARD_DECK_H
