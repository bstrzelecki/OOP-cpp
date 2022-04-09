#pragma once

#include "Entity.h"
#include <list>
#include <iostream>
#include "RenderBatch.h"
#include "Journal.h"


class Entity;
class SerializationContext;


class World {
public:
    World(int x, int y);
    void Run();


    void RunOneFrame();
    void RunOneFrame(char input);
    void Draw();


    void AddEntity(Entity* entity);
    void DeleteEntity(Entity* entity);
    bool IsTileEmpty(int x, int y);

    Entity* GetEntityAtPosition(int x, int y);
    void NotifyUpdate(Entity* sender);

    void Serialize(const std::string& fileName);

    void Load(const std::string& fileName);
    ~World();


    int GetSizeX() const;
    int GetSizeY() const;
private:
    int sizeX, sizeY;
    std::list<Entity*> markedForRemoval, added;
    std::list<Entity*> entities;
    Journal journal;
    RenderBatch* batch;

    void reInit(SerializationContext context);
    bool isDeleted(const Entity* e);
    void dispose();

    static std::string getFileName();

    void applyRemoval();

    void applyAddition();
};



