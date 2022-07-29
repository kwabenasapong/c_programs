#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - entry to fork program
 * Return: 0 always
 */
int main(void)
{

	pid_t pid;

	/* child process is created */
	pid = fork();

	/* checks if fork fails */
	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	/* checks if in child process */
	if (pid == 0)
	{
		printf("child process activated\n");
	}

	/*checks if in parent process */
	else
	{
		wait(NULL);
		sleep(30);
		printf("Parent process initiated\n");
	}
	return (0);
}
