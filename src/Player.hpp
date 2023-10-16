#pragma once

#include "Person.hpp"

class Player : public Person {
private:

public:
    Player(Deck *deck);
    void stand(void);
    void hit(Deck *deck);
};
