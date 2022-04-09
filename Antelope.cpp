#include "Antelope.h"

Antelope::Antelope(int x, int y) : Antelope() {
    position = Position(x,y);
}

Antelope::Antelope() {
    strength = 4;
    initiative = 4;
    symbol = 'A';
}

void Antelope::Update(Journal* journal) {
    Entity::Update(journal);
    Position start = position;
    for (int i = 0; i < 2; ++i) {
        moveAction();
    }
    if(start != position)
        journal->AddEntry(std::string(this->ToString() + " moved from "+start.ToString()+" to "
        +position.ToString()+"."));
}

void Antelope::onAttacked(Entity* entity, Journal* journal) {
    int rng = rand()%2;
    if(rng == 0){
        Animal::onAttacked(entity, journal);
    }else{
        moveAction();
        journal->AddEntry(this->ToString() + " on tile "+lastPosition.ToString()+" was attacked by "
        +entity->ToString()+" and run away to "+position.ToString()+".");
    }
}
