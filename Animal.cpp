#include "Animal.h"

void Animal::Draw(RenderBatch* batch) const {
    batch->Draw(symbol, position.x, position.y);
}

//   0
// 3 + 1
//   2

void Animal::Update(Journal* journal) {
    Entity::Update(journal);
    moveAction();
    if(lastPosition != position)
        journal->AddEntry(std::string(typeid(*this).name()).substr(6) + " moved from "+lastPosition.ToString()+" to "+position.ToString()+".");
}

void Animal::moveAction() {
    while(true){
        int direction = rand()%4;
        if(direction == 0 && move(0, -1)){
            break;
        }
        if(direction == 1 && move(1, 0)){
            break;
        }
        if(direction == 2 && move(0, 1)){
            break;
        }
        if(direction == 3 && move(-1, 0)){
            break;
        }
    }
}

bool Animal::move(int dX, int dY) {
    int newX = position.x + dX;
    int newY = position.y + dY;
    if(newX < 0 || newX >= world->GetSizeX())return false;
    if(newY < 0 || newY >= world->GetSizeY())return false;
    lastPosition = position;
    position.x = newX;
    position.y = newY;
    world->NotifyUpdate(this);
    return true;
}

void Animal::OnCollision(Entity* entity, Journal* journal) {
    if(Animal* animal = dynamic_cast<Animal*>(entity)){
        if(typeid(*this)==typeid(*animal)){
            reproduce(animal, journal);
        }else{
            onAttacked(entity, journal);
        }
    }
}

void Animal::onAttacked(Entity* entity, Journal* journal) {
    if(entity->GetStrength() >= GetStrength()){
        journal->AddEntry(this->ToString() + " on tile "+position.ToString()+" was attacked by "+entity->ToString()+" and lost.");
        world->DeleteEntity(this);
        return;
    }
    if(entity->GetStrength() < GetStrength()){
        journal->AddEntry(this->ToString() + " on tile "+position.ToString()+" was attacked by "+entity->ToString()+" and won.");
        world->DeleteEntity(entity);
    }
}

void Animal::reproduce(Animal* animal, Journal* journal) {
    animal->UndoMovement();
    Entity* e = Entity::GetEntityFromString(typeid(*this).name());
    Animal* child = dynamic_cast<Animal*>(e);
    if(child == nullptr){
        delete e;
        return;
    }
    child->age = 0;
    child->position = position;
    world->AddEntity(child);
    int direction = rand()%4;
    while(direction<4){
        if(direction == 0 && world->IsTileEmpty(position.x, position.y - 1) && child->move(0, -1)){
            break;
        }
        if(direction == 1 && world->IsTileEmpty(position.x + 1, position.y) && child->move(1, 0)){
            break;
        }
        if(direction == 2 && world->IsTileEmpty(position.x, position.y + 1) && child->move(0, 1)){
            break;
        }
        if(direction == 3 && world->IsTileEmpty(position.x - 1, position.y) && child->move(-1, 0)){
            break;
        }
        direction++;
    }
    if(direction==4){
        world->DeleteEntity(child);
    }else {
        journal->AddEntry(this->ToString() + " on tile "+position.ToString()+" successfully mated.");
    }
}

void Animal::UndoMovement() {
    position = lastPosition;
}

void Animal::Empower(int strength) {
    this->strength+=strength;
}
