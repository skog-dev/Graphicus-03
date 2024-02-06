

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "layer.h"

const int MAX_COUCHES = 5;

using namespace std;

class Caneva
{
public:
	Caneva();
	~Caneva();

	bool reset();
	bool resetLayer(int index);

	bool enableLayer(int index);
	bool disableLayer(int index);

	bool addElement(int *element);
	bool removeElement(int index);

	double area();
	bool translate(int deltaX, int deltaY);
	void printTo(ostream &s);

	Vector<Layer<int>> couches;
private:
	
};

Caneva::Caneva()
{
	couches += new Layer<int>();
	couches += new Layer<int>();
	couches += new Layer<int>();

	couches[0]->changeState(ACTIVE);
}

Caneva::~Caneva()
{
}

bool Caneva::reset()
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		couches[i]->reset();
	}

	couches[0]->changeState(ACTIVE);

	return true;
}

bool Caneva::resetLayer(int index)
{

	if (index < 0 || index > couches.getSize() - 1) { return false; }

	if (couches[index]->getState() != ACTIVE) { couches[index]->reset(); }

	else
	{
		couches[index]->reset();
		couches[index]->changeState(ACTIVE);
	}

	return true;
}

bool Caneva::enableLayer(int index)
{
	if (index < 0 || index > couches.getSize() - 1) { return false; }

	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE)
		{
			if (index == i) { return true; }

			couches[i]->changeState(INACTIVE);
			break;
		}
	}

	couches[index]->changeState(ACTIVE);

	return true;
}

bool Caneva::disableLayer(int index)
{
	if (index < 0 || index > couches.getSize() - 1) { return false; }

	if (couches[index]->getState() == ACTIVE) { couches[index]->changeState(INACTIVE); }

	return true;
}

bool Caneva::addElement(int *element)
{
	if (element == NULL) { return false; }

	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE)
		{
			couches[i]->addElement(element);
			break;
		}

		if (i == MAX_COUCHES - 1) { return false; }
	}

	return true;
}

bool Caneva::removeElement(int index)
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE)
		{
			if (couches[index] == nullptr)
			{
				return false;
			}
			couches[i]->removeElement(index);
			break;
		}

		if (i == MAX_COUCHES - 1)
		{
			return false;
		}
	}
	return true;
}

double Caneva::area()
{
	float totalArea = 0;

	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() != INITIALISE) { totalArea += couches[i]->totalArea(); }
	}

	return totalArea;
}

bool Caneva::translate(int deltaX, int deltaY)
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		if (couches[i]->getState() == ACTIVE) { couches[i]->translate(deltaX, deltaY); }

		if (i == couches.getSize() - 1) { return false; }
	}

	return true;
}

void Caneva::printTo(ostream &s)
{
	for (int i = 0; i < couches.getSize(); i++)
	{
		cout << "----- Couche " << i << " -----" << endl;
		cout << "État: " << couches[i]->getState() << endl;

		if (couches[i]->getState() == INITIALISE) { cout << "Initialisée" << endl; }

		if (couches[i]->getState() == ACTIVE) { cout << "Active" << endl; }

		if (couches[i]->getState() == INACTIVE) { cout << "Inactive" << endl; }

		couches[i]->printLayer();
	}

	cout << endl;
}


#endif
