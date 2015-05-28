/*
 *  g++ -c -Wall tmp.cpp; g++ -L /lib tmp.o -lrt -lpthread
 * 	shared memory with vector
 */

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <algorithm>

using namespace boost::interprocess;

int main(void)
{
	shared_memory_object::remove("shared_mem");
	managed_shared_memory segment(create_only, "shared_mem", 65536);

 	typedef allocator<int, managed_shared_memory::segment_manager> ShmemAllocator;
	typedef vector<int, ShmemAllocator> MyVector;
	const ShmemAllocator alloc_inst(segment.get_segment_manager());

	MyVector *myvector = segment.construct<MyVector>("MyVector")(alloc_inst);
	
	for(int i = 0; i < 100; i++)
	{
		myvector->push_back(i);
	}

	return 0;
}

