#include "Sheep.h"

Sheep::Sheep(int x, int y) : Sheep() {
    position = Position(x,y);
}

Sheep::Sheep() {
    symbol = 'S';
    strength = 4;
    initiative = 4;
}
