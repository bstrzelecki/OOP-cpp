#include "Turtle.h"

Turtle::Turtle(int x, int y) : Turtle() {
    position = Position(x,y);
}

Turtle::Turtle() {
    strength = 2;
    initiative = 1;
    symbol = 'T';
}


void Turtle::Update(Journal* journal) {
    int rng = rand()%4;
    if(rng == 0){
        Animal::Update(journal);
    }else{
        Entity::Update(journal);
    }
}

void Turtle::onAttacked(Entity* entity, Journal* journal) {
    if(entity->GetStrength() < 5){
        if(Animal* animal = dynamic_cast<Animal*>(entity)){
            animal->UndoMovement();
            journal->AddEntry(this->ToString() + " on tile "+position.ToString()+" was attacked by "
            +entity->ToString()+" and successfully deflected attack.");
        }
    }else{
        Animal::onAttacked(entity, journal);
    }
}
