#include "shell.h"

/**
 * kbsh_loop - loops shell
 *
 * Return - nothing
 */
void kbsh_loop(void)
{
	char *line, **args, status;

	do {
		printf("$ ");
		line = kbsh_readline();
		args = kbsh_split_line(line);
		status = kbsh_execute(args);

		free(line);
		free(args);
	} while (status);
}
