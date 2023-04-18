#include "main.h"


/**
 * main - shell entry point
 * Return: int
*/
int main(int argc, char *argv[])
{
	pid_t pid;
	char *filename = argv[0];
	char **cmd = NULL;

	(void)argc;

	while(1)
	{
		cmd = prompt();

		if (access(cmd[0], X_OK) != 0)
		{
			perror(filename);
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			return (-1);
		}
		if (pid == 0)
		{
			while(1)
				shell(cmd, filename);
		} else
		{
			wait(NULL);
		}
	}
}
