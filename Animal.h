#pragma once

#include "Entity.h"

class Animal: public Entity {
public:
    Animal(int x, int y):Entity(x,y){}
    Animal():Entity(){}
    void Draw(RenderBatch* batch) const override;
    void Update(Journal* journal) override;
    void UndoMovement();
    void Empower(int strength);
    void OnCollision(Entity* entity, Journal* journal) override;
protected:
    virtual bool move(int dX, int dY);
    virtual void onAttacked(Entity* entity, Journal* journal);
    void moveAction();
    Position lastPosition;

private:
    void reproduce(Animal* animal, Journal* journal);
};



