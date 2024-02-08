
#pragma once

#include <iostream>
#include <string>

#include "vector.h"
#include "shape.h"

#define INITIALISE -1
#define INACTIVE 0
#define ACTIVE 1

class Layer
{
public:
	Layer();
	virtual ~Layer();

	double totalArea();
	bool translate(int x, int y);

	bool reset();
	std::string toString();

	Shape* getElement(int index);
	Shape* removeElement(int index);
	bool addElement(Shape* element);

	bool changeState(int state);
	int getState();
	void getStateStr(char info[]);

	int getSize();

private:
	Vector<Shape> vector;
	int state;
};
