#pragma once

#include <array>
#include <utility>

enum icon {
    Shades,
    Diamond,
    Clubs,
    Heart,
};

class Card {
private:
    icon suit;
    int number;
public:
    Card() noexcept = default;
    Card(const icon type, const int nbr) : suit(type), number(nbr) {};

    icon getSuit();

    int getNumber();
};
