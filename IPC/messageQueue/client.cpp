#include <boost/interprocess/ipc/message_queue.hpp>
#include <iostream>

int main(void)
{
	using namespace boost::interprocess;

	try
	{
		message_queue mq(open_only, "mq");
		size_t recvd_size;
		unsigned int priority;

		for(int i = 0; i < 20; i++)
		{
			int buffer;
			mq.receive((void*) &buffer, sizeof(int), recvd_size, priority);
			if(recvd_size != sizeof(int))
				std::cout << "error" << std::endl;

			std::cout << buffer << " " << recvd_size << " " << priority;
		}
	}
	catch (interprocess_exception& e)
	{
			std::cout << e.what() << std::endl;
	}

	return 0;
}
