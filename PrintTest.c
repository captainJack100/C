#include "PrintTest.h"
#include <stdio.h>
#include <stdlib.h>

void TEST(char *str)
{
	FILE *f = fopen("TEST.txt", "w");
	if (f != NULL)
	{
		fprintf(f, "%s\n", str);
		fclose(f);
	}
}
