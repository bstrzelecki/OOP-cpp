#pragma once


#include "Plant.h"
#include "Animal.h"

class Guarana : public Plant{
public:
    Guarana();
    Guarana(int x, int y);
    void OnCollision(Entity* entity, Journal* journal) override;
};



