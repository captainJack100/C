#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <string>

using namespace std;

#define NUM_THREADS 5

typedef struct thread_data
{
	int thread_id;
	char* message;
} thread_data;

void *PrintHello(void *threadArg)
{
	thread_data *myData = (thread_data *) threadArg;
	cout << "Thread ID: " << myData->thread_id;
	cout << " Message: " << myData->message;
	cout << "\n" << endl;
	pthread_exit(NULL);
}

int main(void) 
{
	pthread_t threads[NUM_THREADS];
	thread_data td[NUM_THREADS];
	int rc;
	int i;

	for(i = 0; i < NUM_THREADS; i++)
	{
		td[i].thread_id = i;
		td[i].message = (char *)"Message";
		rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);

		if(rc)
		{
			cout << "Error: unable to create thread," << rc << endl;
			exit(1);
		}
	}
	
	pthread_exit(NULL);
}
