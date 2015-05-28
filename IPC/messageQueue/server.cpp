/*
 * compiling
 * g++ -c -Wall tmp.cpp; g++ -L /lib tmp.o -lrt -lpthread
 *
 */

#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

int main(void)
{
	using namespace boost::interprocess;

	try
	{
		message_queue mq(create_only, "mq", 20, sizeof(int));
		for(int i = 0; i < 20; i++)
		{
			mq.send(&i, sizeof(int), 0);
		}	
	} 
	catch(interprocess_exception& e)
	{
		std::cout << e.what() << std::endl;
	}	

	return 0;
}
