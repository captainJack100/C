/*
	Divide without using / or *

*/

#include <stdio.h>
#include <stdlib.h>

void divide (int num, int denom) {

	int i = 0;

	while (num >= denom) {
		num -= denom;
		i++;
	}

	printf("%d REMAINDER IS %d\n", i, num);

}

int main(void) {

	divide (10, 3);
	return 0;
}
