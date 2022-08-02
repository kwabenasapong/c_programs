#include "shell.h"

/**
 * main - entry point to kbsh
 * @argc: number of args
 * @argv: arg pointer array to hold cmds and pars
 * Return: exit_success
 */
int main(int argc, char **argv)
{
	/* Load config files, if any */

	/* run command loop */
	kbsh_loop();

	/* Perform any shutdown/clean-up ops */

	return (EXIT_SUCCESS);
}
