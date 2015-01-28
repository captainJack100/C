/*
	This shows a basic version of how several unix commands are implemented.
	1. strelen implementation
	2. strcpy implementation
	3. strcmp implementation
	4. strstr implmentation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define zap(x) {if (x != 0) {free(x); x = 0;}}

//strlen
int strlen1(char *s) {
	
	char *ptr = s;
	while (*ptr++) {}

	return ptr - s;
}

// strcpy
char *strcpy1 (char *s, char *t) {

	char *ptr = s;
	while (*s++ = *t++) {}

	return ptr;
}

// string cmp
int strcmp1(char *s, char *t) {
	
	int n = -1;
	while ((n = *s - *t) == 0 && *s++ && *t++) {}

	return n;
}

// substringfind
char *findsub (char *string, char *pattern) {

	int patternLen = strlen(pattern);
	int stringLen = strlen(string);
	int i = 0;
	int j = 0;
	int strDifference = stringLen - patternLen;

	for (i = 0; i < strDifference; i++) {
		j = 0;
		while ((j < patternLen) && (string[i+j] == pattern[j])) {
			j++;
		}
		if (j == patternLen)
			return string+i;
	}

	return NULL;
}

int main(void) {

	char *x = "fiddasdhellowww";
	char *s = "hello";	
	char *w = "hello";
	char *t = (char *)calloc(1, sizeof(6));
	
	printf("%d \n", strlen1(s));		// length 6
	printf("%s \n", strcpy1(t, s));
	printf("%d \n", strcmp1(s, w));
	printf("%s \n", findsub(x, s));
	
	zap(t);
	return 0;
}
