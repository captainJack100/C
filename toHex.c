#include <stdio.h>

void ToHex(int n) {

	char *htab[ ] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

	if (n > 15)
		ToHex(n/16);
	printf("%s", htab[n % 16]);
}

int main(void) {

	int i = 30;

	ToHex(i);
	printf("\n");

	return 0;
}
