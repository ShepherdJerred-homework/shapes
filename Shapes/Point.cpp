#include "stdafx.h"
#include "Point.h"
#include "Coordinate.h"


Point::Point(Color color, Coordinate coordinate) {
    this->color = color;
    this->coordinate = coordinate;
}

void Point::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate offset(coordinate.x - 1, coordinate.y - 1);
        Point point(Color(100, 100, 100), offset);
        point.draw(image, false);
    }

    image.setPixelColor(coordinate.x, coordinate.y, color);
}
