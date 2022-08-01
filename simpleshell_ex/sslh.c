#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - executes a program via execve
 * Return: 0 always
 */
int main(void)
{
	pid_t pid;
	char *argv[] = {NULL, NULL, NULL};
	char *environ[] = {NULL};
	int val = 0;
	ssize_t num_chars = 0;
	size_t n = 5;
	char *buf = NULL;

	pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		printf("$ ");

		num_chars = getline(&buf, &n, stdin);
		if (num_chars == -1)
			perror("Error");

		printf("buf: %s", buf);

		argv[0] = buf;
		printf("argv[0]: %s", argv[0]);
		printf("argv: %s", *argv);

		val = execve(argv[0], argv, environ);
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
