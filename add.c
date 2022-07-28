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
	int sum;
	pid_t pid;

	if (argc != 3)
	{
		printf("Error: wrong format (./a parameter_1 parameter_2)\n");
		exit(1);
	}

	pid = getpid();

	sum = atoi(argv[1])  + atoi(argv[2]);
	printf("Sum of the %d numbers is: %d\n", argc - 1, sum);
	printf("PID for this instance is: %u\n", pid);
	return (0);

}
