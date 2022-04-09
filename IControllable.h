#pragma once


class IControllable {
public:
    virtual void Update(Journal* journal, char action) =0;
};



