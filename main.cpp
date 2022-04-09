#include <iostream>
#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Belladonna.h"
#include "Hogweed.h"
#include "Human.h"
#include <random>

class Wolf;
class Entity;

int main() {
    std::srand(time(nullptr));
    World world(28,28);

    Entity* wolf = new Wolf(4,5);
    Entity* wolf2 = new Wolf(4,6);
    Entity* wolf3 = new Wolf(5,6);
    Entity* sheep = new Sheep(2,2);
    Entity* sheep2 = new Sheep(4,2);
    Entity* sheep3 = new Sheep(6,2);
    world.AddEntity(wolf);
    world.AddEntity(wolf2);
    world.AddEntity(wolf3);
    world.AddEntity(sheep);
    world.AddEntity(sheep2);
    world.AddEntity(sheep3);

    Entity* fox = new Fox(3,3);
    Entity* fox2 = new Fox(4,4);
    Entity* fox3 = new Fox(5,5);
    world.AddEntity(fox);
    world.AddEntity(fox2);
    world.AddEntity(fox3);

    Entity* turtle = new Turtle(1,5);
    Entity* turtle2 = new Turtle(5,1);
    Entity* turtle3 = new Turtle(5,4);
    world.AddEntity(turtle);
    world.AddEntity(turtle2);
    world.AddEntity(turtle3);

    Entity* antelope = new Antelope(3,6);
    Entity* antelope2 = new Antelope(1,5);
    Entity* antelope3 = new Antelope(2,4);
    world.AddEntity(antelope);
    world.AddEntity(antelope2);
    world.AddEntity(antelope3);

    Entity* grass = new Grass(1,1);
    Entity* dd = new Dandelion(6,1);
    Entity* belladonna = new Belladonna(3,4);
    Entity* hogweed = new Hogweed(0,0);

    world.AddEntity(grass);
    world.AddEntity(dd);
    world.AddEntity(belladonna);
    world.AddEntity(hogweed);

    Entity* human = new Human(4,1);
    world.AddEntity(human);

    world.Run();


    return 0;
}
