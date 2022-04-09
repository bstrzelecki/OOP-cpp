#pragma once


#include "Animal.h"

class Turtle: public Animal {
public:
    Turtle();
    Turtle(int x, int y);
    void Update(Journal* journal) override;
private:
    void onAttacked(Entity* entity, Journal* journal) override;
};




