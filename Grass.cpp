#include "Grass.h"

Grass::Grass() {
    symbol = 'G';
    strength = 0;
}

Grass::Grass(int x, int y) : Grass() {
    position = Position(x,y);
}
