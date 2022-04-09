#pragma once
#include <string>

struct Position{
    Position(int x, int y) {
        this->x=x;
        this->y=y;
    }
    Position(){
        x=0;
        y=0;
    }

    bool operator==(const Position& pos) const {
        return x == pos.x && y == pos.y;
    }

    bool operator!=(const Position& pos) const {
        return !(pos == *this);
    }

    std::string ToString() const{
        return "("+std::to_string(x)+", "+std::to_string(y)+")";
    }

    int x,y;
};
