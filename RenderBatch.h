#pragma once


class RenderBatch {
public:
    RenderBatch(int x, int y);
    void Draw(char symbol, int x, int y);
    void Clear();
    void Render(std::ostream& stream);
    ~RenderBatch();
private:
    int sizeX, sizeY;
    char** map;
};



