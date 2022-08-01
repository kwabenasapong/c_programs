#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char *getCmd(void)
{
	char *buf = NULL;
	size_t n = 0;

	getline(&buf, &n, stdin);
	return (buf);
}


void executeShell(void)
{
	char *cmd_par[100];
	char *userInput, *breakDown;
	int i = 0, val_ex = 0;
	pid_t pid;
	int initiate = 1;

	while (initiate)
	{
		printf("$ ");
		userInput = getCmd();
		if (!*userInput)
			break;

		breakDown = strtok(userInput, " \n");
		while (breakDown && i < 100)
		{
			cmd_par[i++] = breakDown;
			breakDown = strtok(NULL, " \n");
		}
		cmd_par[i] = NULL;

		pid = fork();

		if (pid == -1)
			perror("ERROR");

		if (pid == 0)
		{
			val_ex = execvp(cmd_par[0], cmd_par);
			if (val_ex == -1)
				perror("ERROR");

			printf("Debugging child code\n");
			printf("-----STATUS SYSCALLS-----\n");
			printf("VAL_EX: %d\n", val_ex);
			printf("Value CMD_PAR[0]: %s\n", cmd_par[0]);
		}

		else
		{
			wait(NULL);
			printf("SHELL EXECUTION FINISHED\n");
		}
	}
}

/**
 * main - executes a program via execve
 * Return: 0 always
 */
int main(void)
{
	executeShell();
	return (0);
}
