#include "shell.h"

/**
 * kbsh_start_process - starts processes
 * @args: command args parsed
 * Return: 1 to prompt for input again
 */
int kbsh_start_process(char **args)
{
	pid_t pid, wpid;
	int status, val_exec;

	pid = fork();

	if (pid == 0)
	{
		val_exec = execvp(args[0], args);
		if (val_exec == -1)
			perror("kbsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("kbsh");
	else
	{
		do {
			wpid = waitpid(pid, $status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
