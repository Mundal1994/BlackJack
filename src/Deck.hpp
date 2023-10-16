#pragma once

#include "Card.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <string>

class Deck {
private:
    const int totalDeck = 52;
    std::array<Card, 52> shuffledDeck;
    int indxDeck = 0;

public:
    Deck(void);
    void printShuffledDeck(void);
    Card getCard(void);
    void reShuffleDeck(void);
};
