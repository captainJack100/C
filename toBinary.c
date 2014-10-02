#include <stdio.h>

void ToBin (int n) {

	if (n > 1) 
		ToBin(n/2);
	printf("%d", n%2);
}

int main(void) {

	int i = 2;
	ToBin(i);
	printf("\n");

	return 0;
}
