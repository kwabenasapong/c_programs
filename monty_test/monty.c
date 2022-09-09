#include "monty.h"


/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 when successful
 */
int main(int argc, char **argv)
{
	FILE *stream;
	unsigned int line_number = 0;
	char **tokens;
	char *lines; /* = malloc(sizeof(char *) * 100); */

	if (argc != 2 || argv[1] == NULL)
	{
	fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");


	while (lines)
	{
		lines = getline_input(stream);
		tokens = tokenize(lines);
		printf("%d: %s\n", ++line_number, lines);
		printf("%s, %d\n", tokens[0], atoi(tokens[1]));
	}

	/* free(lines); */
	fclose(stream);
	return (EXIT_SUCCESS);
}
