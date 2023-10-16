#pragma once

#include "Player.hpp"
#include "Dealer.hpp"

class BlackJack {
private:
Deck deck;
Player player;
Dealer dealer;
public:
    BlackJack(void);
    void start();
    void printCurrentHands();
    bool playerTurn();
    bool dealerTurn();
    void statusOfGame();
    void restart();
};
