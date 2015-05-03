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

	return 0;
}
