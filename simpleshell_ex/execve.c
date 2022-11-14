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
	char *argv[4];
	int val = 0, i = 0, j;
	ssize_t num_chars = 0;
	size_t n = 5;
	char *buf = NULL, *token = NULL, *delim = " ";
	char *str = NULL, cmd[] = {'\0'}, *par[] = {NULL};

	pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		printf("$ ");
		num_chars = getline(&buf, &n, stdin);
		printf("buf: %s", buf);

		str = malloc(sizeof(char) * strlen(buf));
		strcpy(str, buf);
		token = strtok(str, delim);

		while (token != NULL)
		{
			argv[i++] = token;
			token = strtok(NULL, delim);
		}
		strcpy(cmd, argv[0]);

		for (j = 0; j < i; j++)
		{
			par[j] = argv[j];
			par[i] = NULL;
		}

		val = execve(cmd, par, NULL);

		printf("Debug child...\nstatus getline: %ld\nstatus exevce: %d\nargv[0]: %s\n", num_chars, val, cmd);

		if (val == -1)
			perror("Error");
	}

	else
	{
		wait(NULL);
		printf("SHELL EXECUTION FINISHED\n");
	}

	free(buf);
	free(str);
	return (0);
}
