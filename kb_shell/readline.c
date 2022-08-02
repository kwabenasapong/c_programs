#include "shell.h"

#define KBSH_RL_BUFSIZE 1024

/**
 * kbsh_readline - read stdin to glean cmds and pars
 * Return: nothing
 */
char *kbsh_readline(void)
{
	int bufsize = KBSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "kbsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* read a character */
		c = getchar();

		/* if we hit EOF, replace with NULL character and return */
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		else
		{
			buffer[position] = c;
		}
		position++;

		/* if we exceed the buffer, reallocate */
		if (position >= bufsize)
		{
			bufsize += KBSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "kbsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}


/**
char *kbsh_readline(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;
	int get_line_num;

	get_line_num = getline(&line, &bufsize, stdin);
	if (get_line_num == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
*/
