#pragma once

#include "Deck.hpp"

#include <vector>
#include <utility>
#include <string>

class Person {
private:
    std::vector<Card> activeCards;
    int currentScore = 0;

public:
    Person(int amount, Deck *deck);
    void initCardDraw(Deck *deck);
    int getScore();
    void calculateScore();
    void drawCard(Deck *deck);
    void printCard(Card *card);
    void printCurrentCards();
    void printTotalRank();
    void clearHand();
};
