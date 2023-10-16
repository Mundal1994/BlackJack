#pragma once

#include "Person.hpp"

class Dealer : public Person {
private:
public:
    Dealer(Deck *deck);
    void hit(Deck *deck);
};
