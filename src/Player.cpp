#include "Player.hpp"

Player::Player(Deck *deck) : Person(2, deck) {
}

void Player::stand(void) {
    std::cout << "Player stands!" << std::endl;
}

void Player::hit(Deck *deck) {
    std::cout << "Player dealt: ";
    drawCard(deck);
}
