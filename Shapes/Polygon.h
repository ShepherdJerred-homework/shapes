#pragma once
#include "Shape.h"
#include <vector>
#include "Coordinate.h"

class Polygon : public Shape {
    vector<Coordinate> points;
public:
    Polygon(Color, vector<Coordinate>);
    void draw(Image, bool) override;
};
