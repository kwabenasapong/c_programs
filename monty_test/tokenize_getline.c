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
	char *delim = "  $\t\r\n\a";
	char *token;
	char **tokens = malloc(sizeof(char *) * bufsize);

	strcpy(str, line_input);
	token = strtok(str, delim);

	while (token)
	{
		tokens[i] = token;
		//printf("%d: %s\n", i, tokens[i]);//Add code to check opcode
		token = strtok(NULL, delim);
		i++;
	}
	return (tokens);
}
