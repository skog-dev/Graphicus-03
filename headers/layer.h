
#pragma once

#include <iostream>
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
	bool translate(int x2, int y2);

	bool reset();
	void printLayer();

	Shape* getElement(int index);
	Shape* removeElement(int index);
	bool addElement(Shape* element);

	bool changeState(int state);
	int getState();

	int getSize();

private:
	Vector<Shape> vector;
	int state;
};
