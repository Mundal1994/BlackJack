#include "Person.hpp"

namespace {

void printNumber(int cardNbr) {
    switch(cardNbr) {
        case 13:
            std::cout << "King";
            break;
        case 12:
            std::cout << "Queen";
            break;
        case 11:
            std::cout << "Jack";
            break;
        case 10:
            std::cout << "Ten";
            break;
        case 9:
            std::cout << "Nine";
            break;
        case 8:
            std::cout << "Eight";
            break;
        case 7:
            std::cout << "Seven";
            break;
        case 6:
            std::cout << "Six";
            break;
        case 5:
            std::cout << "Five";
            break;
        case 4:
            std::cout << "Four";
            break;
        case 3:
            std::cout << "Three";
            break;
        case 2:
            std::cout << "Two";
            break;
        case 1:
            std::cout << "Ace";
            break;
        default:
            std::cout << "Failed. None valid number";
            return;
    }
}

void printSuit(icon type) {
    switch (type) {
        case Shades:
            std::cout << "Shades";
            break;
        case Diamond:
            std::cout << "Diamond";
            break;
        case Clubs:
            std::cout << "Clubs";
            break;
        case Heart:
            std::cout << "Heart";
            break;
    }
}

} // namespace

Person::Person(int amount, Deck *deck) {
    activeCards.reserve(52);
    for (int i = 0; i < amount; ++i) {
        initCardDraw(deck);
    }
}

void Person::initCardDraw(Deck *deck) {
    Card card {deck->getCard()};
    activeCards.push_back(card);
    calculateScore();
}

void Person::drawCard(Deck *deck) {
    initCardDraw(deck);
    printCard(&activeCards[activeCards.size() - 1]);
    std::cout << std::endl;
}

void Person::calculateScore(void) {
    int newCard = activeCards[activeCards.size() - 1].getNumber();
    if (newCard > 10) {
        currentScore += 10;
    } else if (newCard == 1 && currentScore + newCard <= 21) {
        currentScore += 11;
    } else {
        currentScore += newCard;
    }
}

void Person::printCard(Card *card) {
    printNumber(card->getNumber());
    std::cout << " of ";
    printSuit(card->getSuit());
}

void Person::printCurrentCards() {
    for (unsigned int i = 0; i < activeCards.size(); ++i) {
        printCard(&activeCards[i]);
        if (i + 1 == activeCards.size()) {
            printTotalRank();
            break;
        }
        std::cout << ", ";    
    }
}

void Person::printTotalRank() {
    std::cout << " (total rank: " << std::to_string(this->currentScore) << ")" << std::endl;
}

int Person::getScore() {
    return this->currentScore;
}

void Person::clearHand() {
    currentScore = 0;
    while (activeCards.size() > 0) {
        activeCards.pop_back();
    }
}
