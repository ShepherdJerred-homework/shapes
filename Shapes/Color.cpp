#include "stdafx.h"
#include "Color.h"

Color::Color() {
	red = 0;
	green = 0;
	blue = 0;
}

Color::Color(unsigned char red, unsigned char blue, unsigned char green) {
	this->blue = blue;
	this->green = green;
	this->red = red;
}
