#include "stdafx.h"
#include "Circle.h"


Circle::Circle(Color color, Coordinate center, int radius) {
    this->color = color;
    this->center = center;
    this->radius = radius;
}

void Circle::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate offset(center.x - 1, center.y - 1);
        Circle circle(Color(100, 100, 100), offset, radius);
        circle.draw(image, false);
    }

    int y = 0;
    int err = 0;

    while(radius >= y) {
        image.setPixelColor(center.x + radius, center.y + y, color);
        image.setPixelColor(center.x + radius, center.y - y, color);
        image.setPixelColor(center.x - radius, center.y + y, color);
        image.setPixelColor(center.x - radius, center.y - y, color);

        image.setPixelColor(center.x + y, center.y + radius, color);
        image.setPixelColor(center.x + y, center.y - radius, color);
        image.setPixelColor(center.x - y, center.y + radius, color);
        image.setPixelColor(center.x - y, center.y - radius, color);

        y += 1;
        if (err <= 0) {
            err += 2 * y + 1;
        } else {
            radius -= 1;
            err += 2 * (y - radius) + 1;
        }
    }

}
