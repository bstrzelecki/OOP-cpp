#include <string>
#include "SerializationContext.h"
#include "Entry.h"

void SerializationContext::Populate(const std::string& line) {
    std::string name = line.substr(0, line.find(':'));
    std::string valueStr = line.substr(line.find(':')+1, line.size());
    int value = std::stoi(valueStr);
    entries.emplace_back(Entry(name, value));
}

int SerializationContext::GetInt(const std::string& name) {
    for(const Entry& e: entries){
        if(e.name==name){
            return e.value;
        }
    }
    return -1;
}

void SerializationContext::Clear() {
    entries.clear();
}
