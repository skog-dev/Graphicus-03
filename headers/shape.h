
#pragma once

#include <iostream>

struct Coordonnee
{
	int x;
	int y;
};

class Shape
{
public:
	Shape(int x = 0, int y = 0);
	virtual ~Shape();
	void translate(int deltaX, int deltaY);
	Coordonnee getAncrage();
	void setAncrage(Coordonnee c);
	virtual double area() = 0;
	virtual void printTo(std::ostream &s) = 0;

protected:
	Coordonnee ancrage;
};
