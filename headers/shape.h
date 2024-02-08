
#pragma once

#include <iostream>
#include <sstream>
#include <string>


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
	virtual std::string toString() = 0;
	virtual void stateString(char info[]) = 0;

protected:
	Coordonnee ancrage;
};
