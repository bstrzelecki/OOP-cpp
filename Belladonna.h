#pragma once


#include "Plant.h"

class Belladonna : public Plant{
public:
    Belladonna();
    Belladonna(int x, int y);
    void OnCollision(Entity* entity, Journal* journal) override;
};



