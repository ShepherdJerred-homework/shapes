#pragma once
#include <string>
#include "Color.h"
#include "Image.h"

using std::string;

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw(Image, bool) = 0;
protected:
    Color color;
};
