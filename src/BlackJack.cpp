#include "BlackJack.hpp"

#include <iostream>

namespace {

void printWinnerBust(std::string winner, std::string loser) {
    std::cout << loser << " busts!" << std::endl;
    std::cout << winner << " wins!" << std::endl;
}

void printWinner(std::string winner) {
    std::cout << winner << " wins!" << std::endl;
}

void printTie() {
    std::cout << "It's a tie!" << std::endl;
}

bool statusOfGameAfterDraw(int score, std::string loser, std::string winner) {
    if (score <= 21) {
        return true;
    }
    printWinnerBust(winner, loser);
    return false;
}

} // namespace

BlackJack::BlackJack() : deck(), player(&deck), dealer(&deck) {
    std::cout << "Initial draw:" << std::endl;
    printCurrentHands();
}

void BlackJack::printCurrentHands() {
    std::cout << "Player hand: ";
    player.printCurrentCards();
    std::cout << "Dealer hand: ";
    dealer.printCurrentCards();
}

void BlackJack::start() {
    if (!playerTurn()) {
        return;
    }
    if (!dealerTurn()) {
        return;
    }
    statusOfGame();
}

bool BlackJack::playerTurn() {
    while (true) {
        std::cout << "Select action (h = hit, s = stand, q = quit):" << std::endl;

        std::string tempInput;
        std::cin >> tempInput;
        char input = ' ';
        if (tempInput.size() == 1) {
            input = tempInput[0];
        }
        if (input == 'h') {
            player.hit(&deck);
            printCurrentHands();
            if (!statusOfGameAfterDraw(player.getScore(), "Player", "Dealer")) {
                return false;
            }
            continue;
        } else if (input == 's') {
            return true;
        } else if (input == 'q') {
            std::cout << "You quit the game. Bye." << std::endl;
            return false;
        } else {
            std::cout << "Not a valid command. Please read instructions" << std::endl;
        }
    }
}

bool BlackJack::dealerTurn() {
    while (dealer.getScore() < player.getScore()) {
        dealer.hit(&deck);
        printCurrentHands();
        if (!statusOfGameAfterDraw(dealer.getScore(), "Dealer", "Player")) {
            return false;
        }
    }
    return true;
}

void BlackJack::statusOfGame() {
    std::string playerStr {"Player"};
    std::string dealerStr {"Dealer"};
    const int playerScore = player.getScore();
    const int dealerScore = dealer.getScore();

    if (dealerScore < playerScore) {
        printWinner(playerStr);
    } else if (dealerScore == playerScore) {
        printTie();
    } else {
        printWinner(dealerStr);
    }
}

void BlackJack::restart() {
    deck.reShuffleDeck();
    player.clearHand();
    dealer.clearHand();
    player.initCardDraw(&deck);
    player.initCardDraw(&deck);
    dealer.initCardDraw(&deck);
    std::cout << "Initial draw:" << std::endl;
    printCurrentHands();
}
