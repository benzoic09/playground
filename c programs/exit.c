#include "shell.h"

#define MAX_LENGTH 100

/*iiiiiiiiii*
 * executeCommand - Execute command with arguments using execvp function.
 * @command: The command to be executed.
 *
 * Return (Always 0)
 */

void executeCommand(char *command);

int main(void)
{
	char input[MAX_LENGTH];

	while (1)
	{
		printf("$ ");
		if (fgets(input, MAX_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		/* Check for built-in command "exit" */
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting the shell.\n");
			break;
		}
		executeCommand(input);
	}
	return (0);
}

/**
 * executeCommand - Execute command with arguments using execvp function.
 * @command: The command to be executed.
 *
 */
void executeCommand(char *command)
{
	pid_t pid;
	char *args[MAX_LENGTH];
	int argCount = 0;
	char *argToken;
	/*Tokenize the command into arguments*/
	argToken = strtok(command, " ");
	while (argToken != NULL)
	{
		args[argCount++] = argToken;
		argToken = strtok(NULL, " ");
	}
	/* Null-terminate the args array */
	args[argCount] = NULL;
	
	/*Create a child process*/
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)  /*Child process*/
	{
		if (strcmp(args[0], "exit") == 0)
		{
			printf("Exiting the shell.\n");
			exit(EXIT_SUCCESS);
		}
		
		/* Execute the command with arguments */
		execvp(args[0], args);
        
	/* Print an error message if execvp fails */
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);  /*Parent process waits for child to complete*/
	}
}
