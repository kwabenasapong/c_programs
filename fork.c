#include <stdio.h>
#include <unistd.h>

/**
 * main - entry to fork program
 * Return: 0 always
 */
int main(void)
{

	pid_t pid;

	printf("Before fork i was one\n");

	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	printf("After fork i became two\n");
	return (0);


}
