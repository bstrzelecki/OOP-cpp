#include "Belladonna.h"

Belladonna::Belladonna(int x, int y) : Belladonna() {
    position=Position(x,y);
}

Belladonna::Belladonna() {
    symbol = 'B';
    strength = 99;
}

void Belladonna::OnCollision(Entity* entity, Journal* journal) {
    journal->AddEntry(entity->ToString() + " on tile " + entity->GetPosition().ToString()
    + " ate " + this->ToString() + " and died.");
    world->DeleteEntity(entity);
}
