#pragma once
#include "Shape.h"
#include "Coordinate.h"

class Point : public Shape {
	Coordinate coordinate;
public:
	Point(Color, Coordinate);
	void draw(Image, bool) override;
};
