#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_LEN 100

/* Function Declarations */
void executeCommand(char *command);

/**
 * main - Entry point for the shell program.
 *
 * This program implements a basic shell that repeatedly prompts the user
 * for a command and then executes that command in a child process.
 * The user can exit the shell by pressing Ctrl+D or entering an
 * end-of-file marker.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[MAX_LEN];
	int tx = isatty(0);

	/* Main Loop */
	while (1)
	{

	if (tx == 1)
	printf("$ ");
	if (fgets(input, MAX_LEN, stdin) == NULL)
	{
		if (tx == 1)
		printf("\n");
		break;
	}
	input[strcspn(input, "\n")] = '\0';
	executeCommand(input);
	}

	return (0);
}

/**
 * executeCommand - Executes a command using the execve function.
 * @command: The command to be executed.
 */
void executeCommand(char *command)
{
	pid_t pid = fork();
	char *systempath = "/bin/";
	char *fullpath = malloc(strlen(systempath) + strlen(command) + 1);
	char *args[2];

	args[0] = fullpath;
	 args[1] = NULL;

	if (pid == 1)
	{
		perror("fork");
		return;
	}
	else if
		(pid == 0)
		{
			if (fullpath == 0)
			{
				perror("malloc");
				 exit(EXIT_FAILURE);
			}

			strcpy(fullpath, systempath);
			strcat(fullpath, command);
			if (execve(fullpath, args, NULL) == -1)
			{
				perror("execve");
				free(fullpath);
				exit(EXIT_FAILURE);
			}
			free(fullpath);
		}
	else
	{
		wait(NULL);
	}
}

