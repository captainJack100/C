#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

	int LEN = 6;
	char *a = "hello";
	char *b = (char *)calloc(1, sizeof(LEN));
	char *c = (char *)calloc(1, sizeof(LEN));	
	char *d = (char *)calloc(1, sizeof(LEN));

	// copies \0
	strcpy(b, a);
	printf("%s\n", b);

	// may not be null terminated
	// use len of 6 to use \0 from string a
	*c= '\0'; 
	strncpy(c, a, LEN-1);
	printf("%s\n", c);

	// supposedly idiomatic way of doing this
	*d= '\0'; 
	strncat(d, a, LEN-1);
	printf("%s\n", d);
	
	free(b);
	free(c);	
	free(d);

	return 0;
}
