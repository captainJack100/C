#include <iostream>
#include <string>

// base class for accept function
class base 
{

public:
	virtual void accept(class visitor &v) = 0;

};

class one: public base
{
public:
	void accept(visitor &v);
	std::string one_text()
	{
		return "one";
	}
};

class two: public base
{
public:
	void accept(visitor &v);
	std::string two_text()
	{
		return "two";
	}

};

class visitor
{
public:
	void visit(one &e) {std::cout << e.one_text() << std::endl;}
	void visit(two &e) {std::cout << e.two_text() << std::endl;}
};

void one::accept(visitor &v)
{
	v.visit(*this);	
}

void two::accept(visitor &v)
{
	v.visit(*this);
}


int main(void) 
{
	base* list[] = {new one(), new two()};
	visitor v;

	for (int i = 0; i < 2; i++)
		list[i]->accept(v);	

	return 0;
}
