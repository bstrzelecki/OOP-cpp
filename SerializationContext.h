#pragma once


#include <list>
#include "Serializer.h"
#include "Entry.h"

class SerializationContext {
public:
    int GetInt(const std::string& name);
    void Populate(const std::string& line);
    void Clear();
private:
    std::list<Entry> entries;
};



