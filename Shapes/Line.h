#pragma once
#include "Shape.h"
#include "Coordinate.h"

class Line : public Shape {
private:
	Coordinate start;
	Coordinate end;
public:
	Line(Color, Coordinate, Coordinate);
	void draw(Image, bool) override;
};

