/* 
 *  compile: g++ -c -Wall client.cpp; g++ -L /lib client.o -lrt
 *  look in /dev/shm
 *  putting struct in shared memory
 *
 */

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <string>
#include <iostream>

using namespace boost::interprocess;
using namespace std;

typedef struct Point
{
	int x;
	int y;
} Point;

int main(void)
{
	try
	{
		Point *a;
		shared_memory_object shared_mem(open_only, "shared_mem", read_only);
		mapped_region region(shared_mem, read_only);
		a = (Point*)region.get_address();
		
		cout << a->x << " " << a->y << endl;

		shared_memory_object::remove("shared_mem");
	}
	catch(interprocess_exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
