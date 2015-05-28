/*
 * g++ -c -Wall client.cpp; g++ -L /lib client.o -lrt -lpthread
 * using vectors with shared memory
 *
 */

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <algorithm>

using namespace boost::interprocess;

int main(void)
{

	try{
		managed_shared_memory segment(open_only, "shared_mem");
		typedef allocator<int, managed_shared_memory::segment_manager> ShmemAllocator;
		typedef vector<int, ShmemAllocator> MyVector;
		MyVector *myvector = segment.find<MyVector>("MyVector").first;

		for(MyVector::iterator it = myvector->begin(); it != myvector->end(); it++)
		{
			std::cout << *it << std::endl;
		}

		segment.destroy<MyVector>("MyVector");

	}
	catch(...)
	{
		shared_memory_object::remove("shared_mem");
		throw;
	}

	shared_memory_object::remove("shared_mem");
	return 0;
}


