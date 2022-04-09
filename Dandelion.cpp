#include "Dandelion.h"

#define DANDELION_SPREAD 3

Dandelion::Dandelion(int x, int y) : Dandelion() {
    position = Position(x,y);
}

Dandelion::Dandelion() {
    symbol = 'D';
    strength = 0;
}

void Dandelion::Update(Journal* journal) {
    Entity::Update(journal);
    for(int i = 0; i < DANDELION_SPREAD; ++i){
        spread(journal);
    }
}
