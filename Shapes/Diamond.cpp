#include "stdafx.h"
#include "Diamond.h"


Diamond::Diamond(Color color, Coordinate center, int size) {
    this->color = color;
    this->center = center;
    this->size = size;
}

void Diamond::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate offset(center.x - 1, center.y - 1);
        Diamond diamond(Color(100, 100, 100), offset, size);
        diamond.draw(image, false);
    }

    Coordinate top(center.x, center.y + size);
    Coordinate right(center.x + size, center.y);
    Coordinate bottom(center.x, center.y - size);
    Coordinate left(center.x - size, center.y);

    image.addLine(top.x, top.y, right.x, right.y, color);
    image.addLine(right.x, right.y, bottom.x, bottom.y, color);
    image.addLine(bottom.x, bottom.y, left.x, left.y, color);
    image.addLine(left.x, left.y, top.x, top.y, color);

}
