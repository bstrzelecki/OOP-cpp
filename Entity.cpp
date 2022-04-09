#include "Entity.h"

#include "Wolf.h"
#include "Antelope.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"
#include "Human.h"

Entity::Entity(World* world){
    this->world = world;
}

void Entity::SetWorld(World* w) {
    this->world = w;
}

int Entity::GetInitiative() const {
    return initiative;
}

int Entity::GetAge() const {
    return age;
}

void Entity::Update(Journal* journal) {
    age++;
}

const Position& Entity::GetPosition() const {
    return position;
}

int Entity::GetStrength() const {
    return strength;
}

std::string Entity::ToString() {
    return std::string(typeid(*this).name()).substr(6);
}

void Entity::Draw(RenderBatch* batch) const {
    batch->Draw(symbol, position.x, position.y);
}

void Entity::Serialize(Serializer& s) {
    s.SetInt("age", age);
    s.SetInt("x", position.x);
    s.SetInt("y", position.y);
    s.SetInt("strength", strength);
}

void Entity::Deserialize(SerializationContext s) {
    age = s.GetInt("age");
    strength = s.GetInt("strength");
    position = Position(s.GetInt("x"),s.GetInt("y"));
}

#define ADD(x) if(typeid(x).name()==string) return new x()

Entity* Entity::GetEntityFromString(const std::string& string) {
    ADD(Wolf);
    ADD(Sheep);
    ADD(Fox);
    ADD(Antelope);
    ADD(Turtle);
    ADD(Grass);
    ADD(Dandelion);
    ADD(Guarana);
    ADD(Belladonna);
    ADD(Hogweed);
    ADD(Human);
    return nullptr;
}
