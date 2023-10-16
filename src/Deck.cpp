#include "Deck.hpp"

Deck::Deck(void) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 1; j < 14; ++j) {
            Card card {Card(static_cast<icon>(i), j)};
            shuffledDeck.at(indxDeck++) = card;
        }
    }
    indxDeck = 0;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledDeck.begin(), shuffledDeck.end(), g);
};

void Deck::printShuffledDeck(void) {
    std::cout << "totalDeck: " << std::endl;
    for (int i = 0; i < totalDeck; ++i) {
        std::cout << "{" << std::to_string(shuffledDeck.at(i).getSuit()) << ", "
        << std::to_string(shuffledDeck.at(i).getNumber()) << "}" << std::endl;
    }
}

Card Deck::getCard(void) {
    if (indxDeck < totalDeck) {
        return shuffledDeck.at(indxDeck++);
    }
    std::cout << "No more card in Deck" << std::endl;
    return shuffledDeck.at(0);
}

void Deck::reShuffleDeck(void) {
    indxDeck = 0;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shuffledDeck.begin(), shuffledDeck.end(), g);
}
