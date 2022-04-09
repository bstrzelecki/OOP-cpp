#pragma once


#include "Animal.h"
#include "IControllable.h"
#include "InputKeyMap.h"

class Human: public Animal, public IControllable{
public:
    Human();
    Human(int x, int y);
    void Update(Journal* journal, char action) override;

    void Serialize(Serializer& s) override;
    void Deserialize(SerializationContext s) override;
private:
    int cooldown = 0;
    int activeTimer = 0;
    void clearTile(int x, int y);
    void ability(Journal* journal);

    void updateAbility(Journal* journal);
};



