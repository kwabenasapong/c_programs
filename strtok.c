#include <stdio.h>
#include <string.h>

/**
 * main - entry to program for tokenization
 *
 * Return: 0 always
 */
int main(void)
{
	char str[] = "Jesus came to save the world from destruction";
	char *delim = " ";
	char *token;

	token = strtok(str, delim);

	for (; token;)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
