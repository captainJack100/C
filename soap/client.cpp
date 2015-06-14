#include <iostream>
#include "soapcalcProxy.h"
#include "calc.nsmap"

using namespace std;

int main(void)
{
	calcProxy service;
	double result;

	if (service.add(1.0, 2.0, result) == SOAP_OK)
	{
		cout << "one" << endl;
		std::cout << "Sum: " << result << std::endl;
	}
	else
	{
		cout << "two" << endl;
		service.soap_stream_fault(std::cerr);
	}

	return 0;
}
