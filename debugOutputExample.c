#define DEBUG
#include "debug.h"
#include "stdlib.h"

int main(void) {

	int i = 1;
	boolCheck( i != 0 , "Not Zero");
	
	errNoPrint("Test String %s", "prints errno.");
	debug("Formatted print out %s", "Some String");
	debug("Non-formatted string.");
	
	int *p = 0;
	p = (int *)malloc(sizeof(int));
	checkMem(p);
	free(p);

	writeOut("Value of something %d" , 10);
	writeOut("This will append to the file");

	return 0;
}
