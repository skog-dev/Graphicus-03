
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

std::string Circle::toString()
{
    std::ostringstream out;
    out << "C "<< ancrage.x << " " << ancrage.y << " " << r << std::endl;
    return out.str();
}

void Circle::stateString(char info[])
{
    std::ostringstream out;
    out << "Cercle aire = " << area() << std::endl;
    strcpy(info, out.str().c_str());
}
