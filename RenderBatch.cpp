#include <ostream>
#include "RenderBatch.h"

RenderBatch::RenderBatch(int x, int y) {
    sizeX = x;
    sizeY = y;
    map = new char*[x];
    for (int i = 0; i < y; ++i) {
        map[i] = new char[y+1];
    }
}

RenderBatch::~RenderBatch() {
    for (int i = 0; i < sizeY; ++i) {
        delete map[i];
    }
    delete[] map;
}

void RenderBatch::Clear() {
    for (int x = 0; x < sizeX; ++x) {
        for (int y = 0; y <= sizeY; ++y) {
            map[x][y] = y==sizeY?'\0':'-';
        }
    }
}

void RenderBatch::Render(std::ostream& stream) {
    for (int i = 0; i < sizeX; ++i) {
        stream<<map[i]<<"\n";
    }
}

void RenderBatch::Draw(char symbol, int x, int y) {
    if(x < 0 || x >= sizeX || y < 0 || y >= sizeY)return;
    map[y][x] = symbol;
}
