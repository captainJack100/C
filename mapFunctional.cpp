#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#define foreach(c, it) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

using namespace std;

int inc(int i) { return i+1; }

template <typename T, typename FUNC> 
void mapFun(T& original, T& modified, FUNC fun)
{
	transform(original.begin(), original.end(), back_inserter(modified), fun);
}

template <typename T>
typename T::value_type reduce(T& m)
{
	return accumulate(m.begin(), m.end(), 0);
}

int main(void)
{

	vector<int> m;
	vector<int> n;

	for(int i = 0; i < 10; i++)
	{
		m.push_back(i);
	}

	mapFun(m, n, &inc);

	foreach(n, it)
	{
		cout << *it << endl;
	}

	cout << reduce(m) << endl;

	return 0;
}
