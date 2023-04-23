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
	int r, k = 0;
	char *promt_str = "#cisfun$ ";
	int j = str_len(promt_str);
  
  write(1, promt_str, j);

  r = getline(&cmd, &n, stdin);

	if (r == -1)
		exit(0);

	cmd[str_len(cmd) - 1] = '\0';

	token = strtok(cmd, delim);

	while(token != NULL)
	{
		args[k] = token;
		k += 1;
		token = strtok(NULL, delim);
	}

	return (args);
}
