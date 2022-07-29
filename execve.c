#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes a program via execve
 * Return: 0 always
 */
int main(void)
{
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", NULL};
	int val;

	pid = fork();

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		val = execve(argv[0], argv, NULL);

		if (val == -1)
			perror("Error");
	}

	else
	{
		wait(NULL);
		printf("Done with execve!\n");
	}

	return (0);
}
