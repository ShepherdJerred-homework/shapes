#pragma once
#include "Shape.h"
#include "Coordinate.h"

class Rectangle : public Shape {
	Coordinate x;
	Coordinate y;
public:
	Rectangle(Color, Coordinate, Coordinate);
	void draw(Image, bool) override;
};

