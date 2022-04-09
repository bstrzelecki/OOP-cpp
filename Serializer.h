#pragma once


#include <string>
#include <list>
#include "Entry.h"

class Serializer {
public:
    void SetInt(const std::string& name, int value);
    void SetSubEntryName(const std::string& name);
    void Save(const std::string& fileName);
private:
    std::list<Entry> data;
    std::string closed;
};



