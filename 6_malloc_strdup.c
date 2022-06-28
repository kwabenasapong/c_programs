// C program to demonstrate strdup()
#include <stdio.h>
#include <string.h>

int main()
{
	char source[] = "Kwabena Sapong";

	// A copy of source is created dynamically
	// and pointer to copy is returned.
	char* target = strdup(source);

	printf("%s\n", target);
	return 0;
}
