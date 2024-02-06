#include <iostream>
#define COUCHE_H

#include "vector.h"

#define INITIALISE -1
#define INACTIVE 0
#define ACTIVE 1

template <class O>
class Layer
{
public:
	Layer();
	virtual ~Layer();

	double totalArea();
	bool translate(int x2, int y2);
	
	bool reset();
	void printLayer();

	O *getElement(int index);
	O *removeElement(int index);
	bool addElement(O *element);

	bool changeState(int state);
	int getState();

private:
	Vector<O> vector;
	int state;
};

template <class O>
Layer<O>::Layer()
{
	state = INITIALISE;
}

template <class O>
Layer<O>::~Layer() {}

template <class O>
double Layer<O>::totalArea()
{
	float totalArea = 0;

	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr)
		{
			totalArea += *vector[i];
		}
	}

	return totalArea;
}

template <class O>
bool Layer<O>::translate(int x2, int y2)
{
	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr)
		{
			// TODO: Fix this
			// vector[i]->translate(x2, y2);
		}
	}

	return true;
}

template <class O>
bool Layer<O>::reset()
{
	vector.purge();

	state = INITIALISE;

	return true;
}


template <class O>
void Layer<O>::printLayer()
{
	if (vector.isEmpty()) std::cout << "Couche: vide" << std::endl;

	for (int i = 0; i < vector.getCapacity(); i++)
	{
		if (vector[i] != nullptr) std::cout << "Element [" << i << "] : " << *vector[i] << std::endl;
		else std::cout << "Element [" << i << "] : vide" << std::endl;
	}
}

template <class O>
int Layer<O>::getState() { return state; }

template <class O>
O *Layer<O>::getElement(int index) { return vector[index]; }

template <class O>
bool Layer<O>::addElement(O *element)
{
	vector += element;
	return true;
}

template <class O>
O *Layer<O>::removeElement(int index)
{
	return vector.removeElement(index);
}

template <class O>
bool Layer<O>::changeState(int new_state)
{
	state = new_state;
	return true;
}