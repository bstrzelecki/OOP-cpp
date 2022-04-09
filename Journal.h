#pragma once

#include <iostream>
#include <string>
#include <queue>

class Journal {
public:
    void AddEntry(std::string entry);
    void Print(std::ostream& stream);
    void Clear();
private:
    std::queue<std::string> entries;
};



