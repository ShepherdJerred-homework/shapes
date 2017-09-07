#include "stdafx.h"
#include "RightTriangle.h"


RightTriangle::RightTriangle(Color color, Coordinate x, Coordinate y) {
    this->color = color;
    this->x = x;
    this->y = y;
}

void RightTriangle::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate offsetX(x.x - 1, x.y - 1);
        Coordinate offsetY(y.x - 1, y.y - 1);
        RightTriangle rightTriangle(Color(100, 100, 100), offsetX, offsetY);
        rightTriangle.draw(image, false);
    }

    image.addLine(x.x, x.y, y.x, y.y, color); // hypotenuse
    image.addLine(x.x, x.y, x.x, y.y, color); // left leg
    image.addLine(x.x, y.y, y.x, y.y, color); // bottom leg
}
