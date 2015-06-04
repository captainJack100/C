#include <boost/random.hpp>
#include <iostream>
#include <ctime>
#include <cstdint>
#include <vector>

using namespace std;

int getIndx(int min, int max)
{
	std::time_t now = std::time(0);
	boost::random::mt19937 gen{static_cast<std::uint32_t>(now)};
	boost::random::uniform_int_distribution<> dist{min, max};
	return dist(gen);
}

int main(void)
{
	vector<string> quotes = {"one", "two", "three", "four"};
	
	int maxIndx = quotes.size()-1;
	int minIndx = 0;
	int indx = getIndx(minIndx, maxIndx);

	cout << quotes[indx] << endl;	

	return 0;
}

