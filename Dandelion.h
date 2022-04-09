#pragma once


#include "Plant.h"

class Dandelion : public Plant{
public:
    Dandelion();
    Dandelion(int x, int y);
    void Update(Journal* journal) override;
};



