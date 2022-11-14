#include "monty.h"

/**
 * tokenize - breaks down lines of code in file
 * into tokens
 * @line_input: string for line in file
 * Return: tokens
 */
char **tokenize(char *line_input)
{
	int bufsize = 1024, i = 0;
	char *str = malloc(sizeof(char) * strlen(line_input));
	char *delim = " \a\t\r\n$";
	char *token;
	char **tokens = malloc(sizeof(char *) * bufsize);

	strcpy(str, line_input);
	token = strtok(str, delim);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free(line_input);
		exit(EXIT_FAILURE);
	}

	while (token != NULL && i < 3)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[2] = NULL;
	return (tokens);
}
