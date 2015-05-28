/* 
 *  compile: g++ -c -Wall client.cpp; g++ -L /lib client.o -lrt
 *
 *
 *
 */


#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>
#include <iostream>

using namespace boost::interprocess;
using namespace std;

int main(void)
{
	try
	{
		shared_memory_object shared_mem(open_only, "shared_mem", read_only);
		mapped_region region(shared_mem, read_only);
		string str = (char*)region.get_address();
		cout << str << endl;
		shared_memory_object::remove("shared_mem");
	}
	catch(interprocess_exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
