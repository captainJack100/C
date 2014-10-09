/*
	Very simple (naive approach) algorithm for finding matching substring. This is not ideal
	for matching in bioinformatics. See advanced Algorithm book.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *findMatch(char *string, char *pattern) {

	int patternLen = strlen(pattern);
	int stringLen = strlen(string);
	int i = 0;
	int j = 0;

	for (i = 0; i <= (stringLen - patternLen); i++) {
		j = 0;
		
		while (j < patternLen && pattern[j] == string[i+j]) {
			j++;
		}
		
		if (j == patternLen)
			return string + i;

	}
	
	return NULL;
}

int main(void) {

	char *pattern = "ello";
	char *string = "hhelloppp";

	printf("%s\n", findMatch(string, pattern));

	return 0;
}
