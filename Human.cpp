#include "Human.h"

Human::Human(int x, int y) : Human() {
    position = Position(x,y);
}

Human::Human() {
    strength = 5;
    initiative = 4;
    symbol = 'X';
}

void Human::Update(Journal* journal, char action) {
    Entity::Update(journal);
    switch(action){
        case UP:
            move(0,-1);
            break;
        case DOWN:
            move(0,1);
            break;
        case RIGHT:
            move(1,0);
            break;
        case LEFT:
            move(-1,0);
            break;
        case ABILITY:
            if(cooldown==0) {
                ability(journal);
            }else{
                journal->AddEntry(this->ToString()+"'s ability is still on cooldown");
            }
            break;
    }
    updateAbility(journal);
}

void Human::updateAbility(Journal* journal) {
    if(cooldown > 0 && activeTimer == 0)cooldown--;
    if(activeTimer > 0){
        activeTimer--;
        clearTile(position.x, position.y - 1);
        clearTile(position.x + 1, position.y);
        clearTile(position.x, position.y + 1);
        clearTile(position.x - 1, position.y);
    }
    if(cooldown!=0||activeTimer!=0){
        journal->AddEntry(this->ToString()
        + " duration("+std::to_string(activeTimer)+"/5)"+" cooldown("+std::to_string(cooldown)+"/5)");
    }
}

void Human::clearTile(int x, int y) {
    Entity* entity = world->GetEntityAtPosition(x,y);
    if(entity!= nullptr){
        world->DeleteEntity(entity);
    }
}

void Human::ability(Journal* journal) {
    cooldown = 5;
    activeTimer = 5;
    journal->AddEntry(this->ToString() + " successfully activated ability!");
}

void Human::Serialize(Serializer& s) {
    Entity::Serialize(s);
    s.SetInt("cooldown", cooldown);
    s.SetInt("timer", activeTimer);
}

void Human::Deserialize(SerializationContext s) {
    Entity::Deserialize(s);
    cooldown = s.GetInt("cooldown");
    activeTimer = s.GetInt("timer");
}
