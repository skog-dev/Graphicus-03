
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

void Square::printTo(std::ostream& s)
{
    s << ("K %d %d %d", ancrage.x, ancrage.y, w);
}
