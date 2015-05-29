/*
 * Compiling 
 * 
 * g++ -c -Wall server.cpp; g++ -L /lib server.o -lrt
 * look in /dev/shm
 * putting struct in shared memory
 */

#include <boost/array.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;
using namespace std;

typedef struct Point
{
	int x;
	int y;
}Point;

int main(void)
{
	Point a = {1,2};

	try{
		shared_memory_object shared_mem(create_only, "shared_mem", read_write);
		shared_mem.truncate(sizeof(Point));
		mapped_region region(shared_mem, read_write);
		memcpy(region.get_address(), &a, sizeof(Point));		

	} catch (interprocess_exception& e)
	{
		cout << e.what() << endl;
		shared_memory_object::remove("shared_mem");
	}

	return 0;
}
