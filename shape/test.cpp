#include "Shape.h"
#include <iostream>

using namespace std;

int main(void) 
{
	Shape a;
	cout << a.getArea() << endl;
	cout << a.getName() << endl;
	
	Shape b(10, 10, 10, "square");
	cout << b.getArea() << endl;
	cout << b.getName() << endl;

	Shape* c = new Shape(2,2,2);
	cout << c->getArea() << endl;
	cout << c->getName() << endl;
	delete c;

	Shape* d = new Shape;
	cout << d->getName() << endl;
	delete d;

	return 0;
}
