#pragma once
#include "Shape.h"
#include "Coordinate.h"

class Circle : public Shape {
    int radius;
    Coordinate center;
public:
    Circle(Color, Coordinate, int);
    void draw(Image, bool) override;
};

