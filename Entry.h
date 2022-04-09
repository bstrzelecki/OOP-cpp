#include <utility>

#pragma once

struct Entry{
    Entry(std::string name, int value): name(std::move(name)), value(value){}
    std::string name;
    int value;
};

