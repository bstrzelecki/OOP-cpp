#include "Guarana.h"

Guarana::Guarana() {
    symbol = 'G';
    strength = 0;
}

Guarana::Guarana(int x, int y) : Guarana() {
    position = Position(x,y);
}

void Guarana::OnCollision(Entity* entity, Journal* journal) {
    if(Animal* animal = dynamic_cast<Animal*>(entity)){
        animal->Empower(3);
    }
    journal->AddEntry(entity->ToString() + " on tile " + entity->GetPosition().ToString()
    + " ate " + this->ToString() + " and got empowered.");
    Plant::OnCollision(entity, journal);
}
