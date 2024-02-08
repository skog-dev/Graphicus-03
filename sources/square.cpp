
#include "headers/square.h"

Square::Square(int x, int y, int side) : Rectangle(x, y, side, side) {}

Square::~Square() {}

bool Square::changeSize(double side)
{
    if (side < 0) { return false; }

    w = side;
    h = side;

    return true;
}

std::string Square::toString()
{
    std::ostringstream out;
    out << "K " << ancrage.x << " " << ancrage.y << " " << w << std::endl;
    return out.str();
}
