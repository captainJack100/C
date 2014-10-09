/*
	Reverse a string using only pointers.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	char *str = "hello";
	int len = strlen(str); 
	int i = 0;
	char *strTo = (char *)calloc(1, sizeof(len + 1));
	*(strTo + len + 1) = '\0';  // Terminate last part in string

	for (i = 0; i < len; i++) {
		*(strTo + i) = *(str + 4 - i );
	}

	printf("%s\n", strTo);

	free (strTo);

	return 0;
}
