#include "Plant.h"


void Plant::Update(Journal* journal) {
    Entity::Update(journal);
    spread(journal);
}

void Plant::spread(Journal* journal) {
    int rng = rand()%4;
    if(rng == 1){
        int direction = rand()%4;
        if(direction == 0 && world->IsTileEmpty(position.x, position.y - 1)){
            seed(0, -1, journal);
        }
        if(direction == 1 && world->IsTileEmpty(position.x + 1, position.y)){
            seed(1, 0, journal);
        }
        if(direction == 2 && world->IsTileEmpty(position.x, position.y + 1)){
            seed(0, 1, journal);
        }
        if(direction == 3 && world->IsTileEmpty(position.x - 1, position.y)){
            seed(-1, 0, journal);
        }
    }
}

Plant::Plant() {
    initiative = 0;
}

void Plant::seed(int dX, int dY, Journal* journal) {
    int newX = position.x + dX;
    int newY = position.y + dY;
    if(newX < 0 || newX >= world->GetSizeX())return;
    if(newY < 0 || newY >= world->GetSizeY())return;
    Entity* e = Entity::GetEntityFromString(typeid(*this).name());
    Plant* child = dynamic_cast<Plant*>(e);
    if(child == nullptr){
        delete e;
        return;
    }
    child->age = 0;
    child->position = Position(newX, newY);
    world->AddEntity(child);
    journal->AddEntry(this->ToString() + " on tile "+position.ToString()
    +" successfully spread to "+ child->position.ToString() +".");
}

void Plant::OnCollision(Entity* entity, Journal* journal) {
    world->DeleteEntity(this);
    journal->AddEntry(this->ToString() + " on tile " + position.ToString() + " was attacked by " + entity->ToString());
}
