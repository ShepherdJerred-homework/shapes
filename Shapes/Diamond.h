#pragma once
#include "Shape.h"
#include "Coordinate.h"

class Diamond : public Shape {
    Coordinate center;
    int size;
public:
    Diamond(Color, Coordinate, int);
    void draw(Image, bool) override;
};

