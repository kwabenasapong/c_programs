#include <stdio.h>
#include <unistd.h>

/**
 * main - entry to fork program
 * Return: 0 always
 */
int main(void)
{

	pid_t pid;
	pid_t ppid;


	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(40);
		pid = getpid();
		printf("PID: %u\n", pid);
		printf("I am the child\n");
	}
	else
	{
		sleep(10);
		ppid = getpid();
		printf("PPID: %u\n", ppid);
	}
	return (0);
}
