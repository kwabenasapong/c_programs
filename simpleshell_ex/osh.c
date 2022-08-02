#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - executes a program via execve
 * @argc: not used
 * @argv: stores command line args
 * Return: 0 always
 */
int main(int argc __attribute__((unused)), char **argv)
{
	pid_t pid;
	int val = 0, i = 0;
	ssize_t num_chars = 0;
	size_t n = 5;
	char *buf = NULL, *token;

	pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		printf("$ ");
		num_chars = getline(&buf, &n, stdin);
		printf("buf: %s", buf);

		token = strtok(buf, " \n");
		while (token)
		{
			argv[i++] = buf;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

		printf("argv[0]: %s", argv[0]);

		val = execve(argv[0], argv, NULL);
		if (val == -1)
			perror("Error");

		printf("Debugging child...\ngetline: %ld\nexevce: %d\n", num_chars, val);
	}

	else
	{
		wait(NULL);
		printf("SHELL EXECUTION FINISHED\n");
	}
	free(buf);
	return (0);
}
