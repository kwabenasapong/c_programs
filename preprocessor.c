#include <stdio.h>
#include <stdlib.h>

#define SIZE -1024
#define ABS(X) ((X) < 0 ? -(X) : (X))

int main(void)
{
	int s;

	s = 98 + SIZE;
	printf ("Unprocessed: %d\n", s);
	printf ("Processed: %d\n", ABS(s));
	return (EXIT_SUCCESS);
}
