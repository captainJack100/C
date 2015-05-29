#include<fstream>
#include<iostream>
#include<boost/interprocess/sync/file_lock.hpp>
#include<cstdlib>

using namespace std;
using namespace boost::interprocess;

int main(void)
{
	string fileName("test");
	fstream file;
	file.open(fileName.c_str(), ios::out | ios::binary | ios::trunc);

	if(!file.is_open() || file.bad())
	{
		cout << "open failed" << endl;
		exit(-1);
	}

	try
	{
		file_lock f_lock(fileName.c_str());
		f_lock.lock();
		cout << "Locked in progress 1" << endl;
		file.write("Process 1", 9);
		file.flush();
		f_lock.unlock();
		cout << "Unlocked from Process 1" << endl;
	} 
	catch(interprocess_exception& e)
	{
		cout << e.what() << endl;
	}

	file.close();

	return 0;
}
