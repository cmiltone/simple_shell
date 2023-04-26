#include "main.h"

/**
 * exec_command - executes a command with or without args
 * @args: command and list of arguments
 * @filename: the name of the program file
 * Return: 0 on error else 1
*/

int exec_command(char *args[], char *filename)
{
	char *cmd = args[0];
	int k;
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
	{
		perror(filename);
		return (0);
	}
	else if (pid == 0)
	{
		k = execve(cmd, args, environ);

		if (k == -1)
		{
			perror(filename);
			free((*args));
			return (0);
		}
	}
	else
		waitpid(pid, &status, 0);

	return (1);
}

/**
 * shell - starts interractive shell
 * @filename: name of the executable file
 * Return: void
*/

void shell(char *filename)
{
	char **cmd = NULL;

	while (1)
	{
		cmd = prompt();
		if (cmd == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			_exit(1); /*TODO: fix bug*/
		}

		exec_command(cmd, filename);
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
