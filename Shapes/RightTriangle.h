#pragma once
#include "Shape.h"
#include "Coordinate.h"

class RightTriangle : public Shape {
    Coordinate x;
    Coordinate y;
public:
    RightTriangle(Color, Coordinate, Coordinate);
    void draw(Image, bool) override;
};
