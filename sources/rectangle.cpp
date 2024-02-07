
#include "headers/rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : Shape(x, y)
{
    w = (width >= 0) ? width : 1;
    h = (height >= 0) ? height : 1;
}

Rectangle::~Rectangle() {}

bool Rectangle::changeSize(double width, double height)
{
    if (width < 0 || height < 0) { return false; }

    w = width;
    h = height;

    return true;
}

void Rectangle::printTo(std::ostream& s)
{
    s << ("R %d %d %d %d", ancrage.x, ancrage.y, w, h);
}

double Rectangle::area() { return h * w; }

double Rectangle::getWidth() { return w; }

double Rectangle::getHeight() { return h; }
