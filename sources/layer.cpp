
#include <sstream>
#include "headers/layer.h"

Layer::Layer()
{
	state = INITIALISE;
}

Layer::~Layer() { vector.purge(); }

double Layer::totalArea()
{
	float totalArea = 0;

	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr)
		{
			totalArea += vector[i]->area();
		}
	}

	return totalArea;
}

bool Layer::translate(int x, int y)
{
	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr) { vector[i]->translate(x, y); }
	}

	return true;
}

bool Layer::reset()
{
	vector.purge();

	state = INITIALISE;

	return true;
}


std::string Layer::toString()
{
	std::ostringstream out;

	out << "L ";

	switch (getState())
	{
	case 0:
		out << "x" << std::endl;
		break;

	case 1:
		out << "a" << std::endl;
		break;

	default:
		out << "i" << std::endl;
		break;
	}

	for (int i = 0; i < vector.getSize(); i++)
	{
		if (vector[i] != nullptr) { out << vector[i]->toString(); }
	}

	return out.str();
}


int Layer::getState() { return state; }

void Layer::getStateStr(char info[])
{

	switch (getState())
	{
	case 0:
		strcpy(info, "Initialisee");
		break;

	case 1:
		strcpy(info, "Active");
		break;

	default:
		strcpy(info, "Inactive");
		break;
	}

}

Shape* Layer::getElement(int index) { return vector[index]; }

bool Layer::addElement(Shape* element)
{
	vector += element;
	return true;
}

Shape* Layer::removeElement(int index)
{
	return vector.removeElement(index);
}

bool Layer::changeState(int new_state)
{
	state = new_state;
	return true;
}

int Layer::getSize() { return vector.getSize(); }
