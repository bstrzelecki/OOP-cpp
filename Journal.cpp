#include "Journal.h"

void Journal::AddEntry(std::string entry) {
    entries.push(std::move(entry));
}

void Journal::Print(std::ostream& stream) {
    while(!entries.empty()){
        stream<<entries.front()<<"\n";
        entries.pop();
    }
}

void Journal::Clear() {
    while(!entries.empty()){
        entries.pop();
    }
}
