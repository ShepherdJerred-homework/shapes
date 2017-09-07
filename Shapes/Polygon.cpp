#include "stdafx.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Line.h"


Polygon::Polygon(Color color, vector<Coordinate> points) : points(points) {
    this->color = color;
}

void Polygon::draw(Image image, bool drawShadow) {
    int nextPoint = 0;
    for (auto point : points) {
        nextPoint++;
        if (points.back() != point) {
            Coordinate start(point.x, point.y);
            Coordinate end(points[nextPoint].x, points[nextPoint].y);
            Line line(color, start, end);
            line.draw(image, drawShadow);
        } else {
            // Close the polygon
            Coordinate start(point.x, point.y);
            Coordinate end(points[0].x, points[0].y);
            Line line(color, start, end);
            line.draw(image, drawShadow);
        }
    }
}
