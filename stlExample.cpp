#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// using templates to print
template<typename T> void printOut(T &a, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
	}
}

// using iterators
void printVector(vector<int>& m)
{
	for(vector<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << *it << endl;
	}
}

int main(void) 
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> m(a, a+10);
	unordered_map<string, int> n;
	pair<string, int> b;

	b.first = "hello";
	b.second = 10;
	cout << b.first << " " << b.second << endl;

	n["one"] = 1;
	cout << n["one"] << endl;

	reverse(m.begin(), m.end());
	printVector(m);

	if(find(m.begin(), m.end(), 1) != m.end())
		cout << "found it" << endl;

	cout << *max_element(m.begin(), m.end()) << endl;
	cout << *min_element(m.begin(), m.end()) << endl;

	sort(m.begin(), m.end()); // sort ascending
	sort(m.rbegin(), m.rend()); // sort descending reverse iterators
	printVector(m);

	cout << "Array sort" << endl;
	sort(a, a+10);
	reverse(a, a+10);
	printOut(a, 10);

	return 0;
}