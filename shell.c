#include "main.h"

/**
 * exec_command - executes a command with or without args
 * @args: command and list of arguments
 * @filename: the name of the program file
 * Return: void
*/

void exec_command(char *args[], char *filename)
{
	char *cmd = args[0];
	int k = execve(cmd, args, __environ);

	if (k == -1)
		perror(filename);
}

/**
 * shell - starts interractive shell
 * @filename: name of the executable file
 * Return: void
*/

void shell(char *filename)
{
	pid_t pid;
	char **cmd = NULL;

	while (1)
	{
		cmd = prompt();
		if (cmd == NULL)
		{
			break; /*maybe exit?*/
		}

		if (access(cmd[0], X_OK) != 0)
		{
			cmd[0] = get_command_in_path(cmd[0]);

			if (cmd[0] == NULL)
			{
				perror(filename);
				continue;
			}
		}

		pid = fork();
		if (pid == -1)
		{
			perror(filename);
			break;
		}
		if (pid == 0)
			exec_command(cmd, filename);
		else
			wait(0);
	}
}
