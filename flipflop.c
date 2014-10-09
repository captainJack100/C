/*
	cool xor flip flop trick.

	note    a^(a^b) = b
			b^(a^b) = a

	NOTE: This doesn't work with pointers. Also, this is 
	a horrible idea for production code.
*/

#include <stdio.h>

int main(void) {

	// values to alternate
	int a = 1;
	int b = 13;

	// indices
	int i = 0;
	int n = 0;

	for (i = 0, n = a; i < 10; i++, n ^= (a^b))
		printf("%d ", n);

	return 0;
}
