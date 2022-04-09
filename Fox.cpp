#include "Fox.h"

Fox::Fox(int x, int y) : Fox() {
    position = Position(x,y);
}

Fox::Fox() {
    strength = 3;
    initiative = 7;
    symbol = 'F';
}

bool Fox::move(int dX, int dY) {
    if(canMove(position.x+dX,position.y+dY)){
        return Animal::move(dX, dY);
    }else{
        return false;
    }
}

bool Fox::canMove(int x, int y) {
    Entity* e = world->GetEntityAtPosition(x,y);
    if(e== nullptr)return true;
    return e->GetStrength() <= GetStrength();
}
