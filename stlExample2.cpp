#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#define foreach(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

using namespace std;

int myFunction(int x, int y) { return x+2*y; }

int main(void)
{

	// set intersection
	int data1[] = {1,2,5,6,8,9, 10};
	int data2[] = {2,3,4,7,8,10};
	vector<int> v1(data1, data1+sizeof(data1)/sizeof(data1[0]));
	vector<int> v2(data2, data2+sizeof(data2)/sizeof(data2[0]));
	vector<int> tmp(max(v1.size(), v2.size()));
	vector<int> res = vector<int> (tmp.begin(), set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), tmp.begin()));

	foreach(res, it)
	{
		cout << *it << endl;
	}

	// accumulate
	int numbers[] = {10, 20, 30};
	cout << accumulate(numbers, numbers+3, 100, myFunction) << endl;
	cout << accumulate(numbers, numbers+3, 0) << endl;

	// inner product
	int series1[] = {10, 20, 30};
	int series2[] = {1,2,3};	
	cout << inner_product(series1, series1+3, series2, 0) << endl;

	

	return 0;
}
