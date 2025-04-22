#ifndef CARD_DECK_H
#define CARD_DECK_H

#include <vector>

#include "card.h"
namespace memorix {

enum class CardViewWay
{
    FRONT,
    BACK,
};

class CardDeck
{
public:
    explicit CardDeck(std::vector<Card> cards)
        : cards_(std::move(cards)), current_card_(0), view_way_(CardViewWay::FRONT) {}

    void next();
    void previous();
    const CardViewWay viewWay() const;
    void setCardViewWay(CardViewWay view_way);
    const std::string_view current() const;

private:
    std::vector<Card> cards_;
    std::size_t current_card_;
    CardViewWay view_way_;
};

}  // namespace memorix

#endif  // !CARD_DECK_H
