#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape(double a, double b, double c, string n):length(a), width(b), height(c), name(n)
{
}

double Shape::getArea(void)
{
	return length*width*height;
}

string Shape::getName(void)
{
	return name;
}
