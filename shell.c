#include "main.h"

/**
 * shell - starts an interrractive shell
 * @args: command and list of arguments
 * @filename: the name of the program file
 * Return: void
*/

void shell(char *args[], char *filename)
{
	char *cmd;
	int k;
if (args == NULL || args[0] == NULL)
{
	perror(filename);
}
cmd = args[0];
k = execve(cmd, args, NULL);
if (k == -1)
{
	perror(filename);
}
}
