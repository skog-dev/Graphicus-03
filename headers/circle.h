
#pragma once

#include "shape.h"

#define PI 3.14159265358979323846

class Circle : public Shape
{
public:
    Circle(int x1 = 0, int y1 = 0, int rayon = 1);
    ~Circle();
    double area() override;
    std::string toString() override;
    void stateString(char info[]) override;
    bool changeSize(int rayon);
    int getRayon();

private:
    int r;
};
