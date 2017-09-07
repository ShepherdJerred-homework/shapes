#include "stdafx.h"
#include "Line.h"

Line::Line(Color color, Coordinate start, Coordinate end) {
    this->color = color;
    this->start = start;
    this->end = end;
}

void Line::draw(Image image, bool drawShadow) {

    if (drawShadow) {
        Coordinate startOffset(start.x - 1, start.y - 1);
        Coordinate endOffset(end.x - 1, end.y - 1);
        Line line(Color(100, 100, 100), startOffset, endOffset);
        line.draw(image, false);
    }

    image.addLine(start.x, start.y, end.x, end.y, color);
}
