#include "main.h"

/**
 * prompt - get user command
 * Return: command
*/

char **prompt()
{
	char *cmd = NULL;
	size_t n = 10;
	char *token;
	char *delim = " ";
	char **args = malloc(sizeof(char *) * n);
	int k = 0;
	char *promt_str = "#cisfun$ ";
	int j = strlen(promt_str);
  
  write(1, promt_str, j);

  getline(&cmd, &n, stdin);

	cmd[strlen(cmd) - 1] = '\0';

	if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}

	if (strcmp(cmd, "env") == 0)
	{
		args[0] = "/usr/bin/env";
		return (args);
	}

	token = strtok(cmd, delim);

	while(token != NULL)
	{
		args[k] = token;
		k += 1;
		token = strtok(NULL, delim);
	}

	return (args);
}
