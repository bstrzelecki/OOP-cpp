#pragma once


#include "Animal.h"

class Antelope: public Animal{
public:
    Antelope();
    Antelope(int x, int y);
    void Update(Journal* journal) override;
protected:
    void onAttacked(Entity* entity, Journal* journal) override;
};



