#pragma once


#include "Animal.h"

class Fox : public Animal{
public:
    Fox();
    Fox(int x, int y);
protected:
    bool move(int dX, int dY) override;
private:
    bool canMove(int x, int y);
};



