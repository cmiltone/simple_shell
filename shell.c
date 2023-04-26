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
	int k = execve(cmd, args, environ);

	if (k == -1)
	{
		perror(filename);
		free((*args));
	}
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
	int status;

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
		if (pid > 0)
		{
			waitpid(pid, &status, 0);
		}
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


/**
 * ctrl_c - listens for Ctrl+C then
 * writes a newline and prompts the user again
 *
 * @sig: input signal to confirm is SIGINT
 * Return: void
*/

void ctrl_c(int sig)
{
	char *prompt_str = "\n$ ";
	int is_valid;

	if (sig == SIGINT)
	{
		is_valid = isatty(STDIN_FILENO);
		if (is_valid == 1)
			write(STDOUT_FILENO, prompt_str, str_len(prompt_str));
	}
}
