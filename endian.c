/*
 *	Determine endianess of machine
 *	Little endian ---> 67 45 23 01  Last byte stored first
 *	Big Endian ---> 01 23 45 67		first byte stored first
 *	char has access to individual bytes
 *	Network order is big endian. ASCII files are independent (they have 1 byte units). JPEG are big endian.
 */

#include <stdio.h>

// show the memory representation 
void memRep(char *start, int n) {
	int i = 0;
	for (i = 0; i < n; i++)
		printf (" %.2x", start[i]);
	printf("\n");
}

// fast check
void checkEndianess(){
	unsigned int i = 1;
	char *c = (char *)&i;
	if (*c) 
		printf("Little endian");
	else
		printf("Big endian");

	printf("\n");
} 

// Test
int main(void) {

	int i = 0x01234567;
	memRep((char *)&i, sizeof(i));
	checkEndianess();

	return 0;
}
