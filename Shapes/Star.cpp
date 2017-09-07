#include "stdafx.h"
#include "Star.h"


Star::Star(Color color, Coordinate center, int size) {
    this->color = color;
    this->center = center;
    this->size = size;
}

void Star::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate offset(center.x - 1, center.y - 1);
        Star star(Color(100, 100, 100), offset, size);
        star.draw(image, false);
    }

    int halfSize = size / 2;

    image.addLine(center.x, center.y + halfSize, center.x, center.y - halfSize, color);
    image.addLine(center.x + halfSize, center.y, center.x - halfSize, center.y, color);
    image.addLine(center.x - halfSize, center.y + halfSize, center.x + halfSize, center.y - halfSize, color);
    image.addLine(center.x - halfSize, center.y - halfSize, center.x + halfSize, center.y + halfSize, color);

}
