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

		/* here code checks whether an executable really does exist*/
		if (cmd[0] == NULL || access(cmd[0], X_OK) != 0)
		{
			perror(filename);
			break;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			return (-1);
		}

		if (pid == 0)
		{
			/* At this instance, we display the child process */
			while(1)
				shell(cmd, filename);
		} else
		{
			/* At this instance, we display the valid parent process*/
			wait(NULL);
		}

		/* Here we free ideally the memory allocated by the prompt() */
		free(cmd);
	}

	/* To handle exit */
int main (int args __attribute__((unused)), char **argv, char **env)
{
	int should_free = 0;
	info_t info = {NULL, env, 0, 0};
	char *line =NULL;

	info.argv = argv;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = read_line(&should_free);
		if (line == NULL)
			break;
		execute_command(&info);
		while (should_free)
		{
			free(line);
			should_free--;
		}
	}

	exit(info.status);
}
	return (0);



