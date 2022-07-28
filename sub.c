#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - entry to add progrom
 * @argc: # of arguments
 * @argv: arguments
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int sub;
	pid_t pid;
	pid_t ppid;

	if (argc != 3)
	{
		printf("Error: wrong format (./a parameter_1 parameter_2)\n");
		exit(1);
	}

	pid = getpid();
	ppid = getppid();

	sub = atoi(argv[1])  - atoi(argv[2]);
	printf("Subtract the %d numbers to get: %d\n", argc - 1, sub);
	printf("PID for this instance is: %u\n", pid);
	printf("PPID for this instance is: %u\n", ppid);
	return (0);

}
