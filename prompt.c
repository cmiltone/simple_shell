#include "main.h"

/**
 * prompt - get user command
 * Return: command
*/

char **prompt()
{
	char *cmd = NULL;
	size_t n = 10000;
	char *token;
	char *delim = " ";
	char **args = malloc(sizeof(char *) * n);
	int r, k = 0;
	char *prompt_str = "$ ";
	int j = str_len(prompt_str);

	write(1, prompt_str, j);

	r = getline(&cmd, &n, stdin);

	if (r == -1)
		return (NULL);

	cmd[str_len(cmd) - 1] = '\0';

	if (str_len(cmd) == 0)
		return (NULL);

	token = strtok(cmd, delim);

	while (token != NULL)
	{
		args[k] = token;
		k += 1;
		token = strtok(NULL, delim);
	}

	return (args);
}
