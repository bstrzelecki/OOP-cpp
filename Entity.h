#pragma once

#include <memory>
#include "Position.h"
#include "World.h"
#include "Journal.h"
#include "Serializer.h"
#include "SerializationContext.h"



class RenderBatch;
class World;

class Entity{
public:
    Entity() = default;
    Entity(int x, int y): position(x,y){}
    explicit Entity(World* world);

    static Entity* GetEntityFromString(const std::string& string);

    virtual void Draw(RenderBatch* batch) const;
    virtual void Update(Journal* journal);

    void SetWorld(World* w);
    virtual void Serialize(Serializer& s);
    virtual void Deserialize(SerializationContext s);

    std::string ToString();
    int GetInitiative() const;
    int GetAge() const;
    int GetStrength() const;

    const Position& GetPosition() const;
    virtual void OnCollision(Entity* entity, Journal* journal) =0;

protected:
    int age = 0;
    char symbol = '?';
    int strength = -1;
    int initiative = -1;
    Position position = Position(-1,-1);
    World* world = nullptr;
};



