#include "monty.h"
#define _GNU_SOURCE


/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0 when successful
 */
int main(int argc, char **argv)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 1;
	//char **token = NULL;

	if (argc != 2 || argv[1] == NULL)
	{
	fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("%d: ", line_number);
		fwrite(line, nread, 1, stdout);
		tokenize(line);
		line_number++;
	}

	free(line);
	fclose(stream);
	return (EXIT_SUCCESS);
}
