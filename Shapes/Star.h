#pragma once
#include "Shape.h"
#include "Coordinate.h"

class Star : public Shape {
    Coordinate center;
    int size;
public:
    Star(Color, Coordinate, int);
    void draw(Image, bool) override;
};

