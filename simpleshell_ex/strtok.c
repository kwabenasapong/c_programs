#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * breakdown_cmd - entry to program for tokenization
 *@src: accepts strings
 * Return: 0 always on success
 */
char *breakdown_cmd(char *src)
{
	char *str = malloc(sizeof(char) * strlen(src));
	char *delim = " ";
	char *token, *arr[3];
	int i = 0;

	strcpy(str, src);
	token = strtok(str, delim);

	while (token != NULL)
	{
		arr[i++] = token;
		token = strtok(NULL, delim);
	}

	for (i = 0; i < 3; i++)
		printf("arr[%d]: %s\n", i, arr[i]);

	free(str);
	return (0);
}

/**
 * main - entry program
 * @ac: number of args
 * @av: pointer to array of args
 *
 * Return: 0 always(success)
 */
int main(int ac, char **av)
{
	char *str = av[1];

	breakdown_cmd(str);
	return (0);
}
