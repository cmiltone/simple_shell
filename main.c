#include "main.h"


/**
 * main - shell entry point
 * Return: int
*/
int main(int argc, char *argv[])
{
	pid_t pid = fork();

	(void)argc;

	if (pid == -1)
	{
		return (-1);
	}

	if (pid == 0)
	{
		while(1)
		{
			shell(argv[0]);
		}
	} else
	{
		wait(NULL);
		// shell();
		printf("Done with execve\n");
	}
}