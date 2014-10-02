#include <stdio.h>

void toHex(int n) {

	char *htab[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

	if (n > 15)
		toHex(n/16);
	printf("%s", htab[n%16]);
}

void toBin(int n) {

	if (n > 1)
		toBin(n/2);
	printf("%d", n%2);
}


int main(void) {

	int i = 30;
	int j = 3;
	
	toHex(i);
	puts("");
	toBin(j);

	return 0;
}
