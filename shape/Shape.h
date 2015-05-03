#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape 
{
	public:
		string getName(void);
		double getArea(void);
		Shape(double a=0, double b=0, double c=0, string n="");
	private:
		string name;
		double length;
		double width;
		double height;
};

#endif
