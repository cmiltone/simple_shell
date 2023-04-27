#include "main.h"

/**
 * prompt - get user command
 * Return: command
*/

char **prompt()
{
	char *cmd = NULL, *token,
	 *prompt_str = "$ ", *delim = " ";
	size_t n = 512;
	char **args = malloc(sizeof(char *) * n);
	int r, k = 0, w = 0,
	j = str_len(prompt_str);
	if (args == NULL)
	{
		perror("Malloc Error");
		return (NULL);
	}
	if (isatty(STDIN_FILENO))
		w = write(STDOUT_FILENO, prompt_str, j);
	if (w < 0)
	{
		perror("Write Error");
		return (NULL);
	}
	r = getline(&cmd, &n, stdin);
	if (r == -1)
		return (NULL);
	if (str_len(cmd) == 0)
		return (NULL);
	cmd[str_len(cmd) - 1] = '\0';
	token = strtok(cmd, delim);
	while (token != NULL)
	{
		args[k] = token;
		k += 1;
		token = strtok(NULL, delim);
	}

	return (args);
}
