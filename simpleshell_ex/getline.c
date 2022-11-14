#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry to program to get input from stdin
 * Return: 0 always
 */
int main(void)
{
	size_t n;
	char *buf;

	n = 5;

	buf = NULL;

	printf("$ ");
	getline(&buf, &n, stdin);

	printf("%s\n", buf);

	free(buf);

	return (0);
}
