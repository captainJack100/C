#include <iostream>
#include "shape.h"
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Time
{
	int h;
	int m;
	int s;
	string name;
} Time;

class CompareTime
{	
	public:
		bool operator()(Time& t1, Time& t2)
		{
			if(t1.h < t2.h) return true;
			if(t1.h == t2.h && t1.m < t2.m) return true;
			if(t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
		}
};

int main(void) 
{

	// priority queue by user defined type
	priority_queue<Time, vector<Time>, CompareTime> pq;

	Time t[4] = { {3,2,40, "one"}, {3,2,26, "two"}, {5,16,13, "three"}, {5,15,20, "four"} };
	
	for(int i = 0; i < 4; i++)
		pq.push(t[i]);

	while(! pq.empty())
	{
		cout << pq.top().name << endl;
		pq.pop();
	}

	// simple queue
	priority_queue<int> z;
	z.push(100);
	z.push(10);
	z.push(1);
	z.push(100);
	z.push(10000);

	while(!z.empty())
	{
		cout << z.top() << endl;
		z.pop();
	}
	
	return 0;
}
