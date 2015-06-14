#include <iostream>
#include "soapcalcService.h"
#include "calc.nsmap"
#include "soapH.h"

using namespace std;

int calcService::add(double a, double b, double &result)
{
	result = a +b;
	return SOAP_OK;
}

int calcService::sub(double a, double b, double &result) 
{ 
	// dummy 
	return SOAP_OK; 
}
		
int calcService::mul(double a, double b, double &result) 
{ 
	// dummy 
	return SOAP_OK; 
}
		
int calcService::div(double a, double b, double &result) 
{ 
	// dummy 
	return SOAP_OK; 
}
		
int calcService::pow(double a, double b, double &result) 
{ 
	// dummy 
	return SOAP_OK; 
	
}

int main()
{
	calcService c;
	c.run(80);

	return c.serve();	

}
