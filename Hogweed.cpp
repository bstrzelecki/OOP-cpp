#include "Hogweed.h"
#include "Animal.h"

Hogweed::Hogweed() {
    symbol = 'H';
    strength = 10;
}

Hogweed::Hogweed(int x, int y) : Hogweed() {
    position = Position(x,y);
}

void Hogweed::Update(Journal* journal) {
    clearTile(0, -1);
    clearTile( 1, 0);
    clearTile(0, 1);
    clearTile(-1, 0);

    Plant::Update(journal);
}

void Hogweed::clearTile(int x, int y) {
    Entity* entity = world->GetEntityAtPosition(position.x + x, position.y + y);
    if(entity!= nullptr && dynamic_cast<Animal*>(entity) != nullptr){
        world->DeleteEntity(entity);
    }
}
