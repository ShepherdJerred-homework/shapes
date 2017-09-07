#include "stdafx.h"
#include "Rectangle.h"


Rectangle::Rectangle(Color color, Coordinate x, Coordinate y) {
    this->color = color;
    this->x = x;
    this->y = y;
}

void Rectangle::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate offsetX(x.x - 1, x.y - 1);
        Coordinate offsetY(y.x - 1, y.y - 1);
        Rectangle rectangle(Color(100, 100, 100), offsetX, offsetY);
        rectangle.draw(image, false);
    }

    image.addLine(x.x, x.y, y.x, x.y, color); // top left     -> top right
    image.addLine(y.x, x.y, y.x, y.y, color); // top right    -> bottom right
    image.addLine(y.x, y.y, x.x, y.y, color); // bottom right -> bottom left
    image.addLine(x.x, y.y, x.x, x.y, color); // bottom left  -> top left
}
