#pragma once


#include "Belladonna.h"

class Hogweed : public Belladonna{
public:
    Hogweed();
    Hogweed(int x, int y);
    void Update(Journal* journal) override;
private:
    void clearTile(int x, int y);
};



