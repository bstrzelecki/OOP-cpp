#include <iostream>
#include <fstream>
#include "Serializer.h"
#include "Entry.h"

void Serializer::SetInt(const std::string& name, int value) {
    for(Entry e: data){
        if(e.name == name){
            e.value=value;
            return;
        }
    }
    data.emplace_back(name,value);
}

void Serializer::SetSubEntryName(const std::string& name) {
    for(const Entry& e: data){
        closed+=e.name+":"+std::to_string(e.value)+"\n";
    }
    data.clear();
    closed+="!"+name+"!\n";
}

void Serializer::Save(const std::string& fileName) {
    std::ofstream stream;
    stream.open(fileName);
    SetSubEntryName("");
    stream<<closed;
    stream.close();
}
