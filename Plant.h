#pragma once


#include "Entity.h"

class Plant: public Entity {
public:
    Plant();
    void Update(Journal* journal) override;
    void OnCollision(Entity* entity, Journal* journal) override;
protected:
    void spread(Journal* journal);
    void seed(int dX, int dY, Journal* journal);
};



