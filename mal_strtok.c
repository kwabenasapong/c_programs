#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - entry to program for tokenization
 * using malloc to gain access to
 * string literal
 *
 * Return: 0 always
 */
int main(void)
{
	char *src = "Jesus came to save the world from destruction";
	char *str = malloc(sizeof(char) * strlen(src));
	char *delim = " ";
	char *token;

	strcpy(str, src);
	token = strtok(str, delim);

	for (; token;)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
