#include "Dealer.hpp"

Dealer::Dealer(Deck *deck) : Person(1, deck) {}

void Dealer::hit(Deck *deck) {
    std::cout << "Dealer dealt: ";
    drawCard(deck);
}
