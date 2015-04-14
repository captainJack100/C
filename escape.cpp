/*
 * Escape characters in c string. Good if mysql_real_escape isn't available.
 *
 */

#include <iostream>

using namespace std;

int main(void) {

	char myStr[] = "This i's a C String";
	string str = myStr;

	cout << str << endl;
	string out;

	for (string::const_iterator it = str.begin(); it != str.end(); it++){
		char currValue = *it;
		switch (currValue)
		{
			case L'\'':
				out.append("\\'");
				break;
			default:
				out.push_back(currValue);		
		}
	}

	cout << out << endl;
	return 0;
}	
