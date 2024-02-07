
#pragma once

#include "rectangle.h"

class Square : public Rectangle
{
public:
    Square(int x = 0, int y = 0, int side = 1);
    ~Square();
    void printTo(std::ostream &s) override;
    bool changeSize(double side);
};
