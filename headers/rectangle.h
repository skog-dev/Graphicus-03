
#pragma once

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(int x = 0, int y = 0, int width = 1, int height = 1);
    ~Rectangle();
    virtual void printTo(std::ostream &s) override;
    double area() override;
    bool changeSize(double width, double height);
    double getWidth();
    double getHeight();

protected:
    double w;
    double h;
};
