
#include "headers/circle.h"

Circle::Circle(int x, int y, int rayon) : Shape(x, y) { r = (rayon > 0) ? rayon : 1; }

Circle::~Circle() { }

double Circle::area() { return PI * r * r; }

int Circle::getRayon() { return r; }

bool Circle::changeSize(int rayon)
{
    r = rayon;
    return true;
}

void Circle::printTo(std::ostream& s)
{
    s << ("C %d %d %d, ", ancrage.x, ancrage.y, r);
}
