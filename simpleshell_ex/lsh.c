#define _BSD_SOURCE_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

char *userInput()
{
	char *input = NULL;
	size_t size = 0;
	getline(&input, &size, stdin);
	return (input);
}

void driveLoop(void)
{
	char *toks[100]; // max of 99 tokens (last must be NULL)

	for (;;)
	{

		printf("> ");
		char *command = userInput();
		if (!*command)
			break; // exit if empty string (Ctrl-D)

		int i = 0;
		char *tok = strtok(command, " \t\n");
		while (tok && i < 99)
		{
			toks[i++] = tok;
			tok = strtok(NULL, " \t\n");
		}
		toks[i] = NULL;

		pid_t cFork = fork();
		if (cFork == (pid_t)-1)
			perror("fork");
		else if (cFork == 0)
		{ // child
			execvp(toks[0], toks);
			perror("exec"); // probably command not found
		}
		else // parent
			wait(NULL);
	}
}

int main(void)
{
	driveLoop();
	return (0);
}

