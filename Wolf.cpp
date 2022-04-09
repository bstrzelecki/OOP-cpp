#include "Wolf.h"

Wolf::Wolf() {
    strength = 9;
    initiative = 5;
    symbol = 'W';
}

Wolf::Wolf(int x, int y) : Wolf() {
    position = Position(x,y);
}
