
#include "headers/shape.h"

Shape::Shape(int x, int y)
{
	ancrage.x = x;
	ancrage.y = y;
}

Shape::~Shape() {}

void Shape::translate(int deltaX, int deltaY)
{
	ancrage.x += deltaX;
	ancrage.y += deltaY;
}

Coordonnee Shape::getAncrage() { return ancrage; }

void Shape::setAncrage(Coordonnee c) { ancrage = c; }
