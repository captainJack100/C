/*
 * Compiling 
 * 
 * g++ -c -Wall server.cpp; g++ -L /lib server.o -lrt
 */

#include <boost/array.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;
using namespace std;

int main(void)
{
	/*
	struct shm_remove
    {
		shm_remove() { shared_memory_object::remove("shared_mem"); }
		~shm_remove(){ shared_memory_object::remove("shared_mem"); }
	} remover;
	*/

	try{
		
		shared_memory_object shared_mem(create_only, "shared_mem", read_write);
		shared_mem.truncate(256);
		mapped_region region(shared_mem, read_write);
		//memset(region.get_address(), 1, region.get_size());
		strcpy((char*)region.get_address(), "hello, world\n");	

	} catch (interprocess_exception& e)
	{
		cout << e.what() << endl;
		shared_memory_object::remove("shared_mem");
	}

	return 0;
}
