#include "main.h"

/**
 * get_env - gets an evironment variable
 * @env: the variable name
 * 
 * Return: the value of the varible
*/

char *get_env(char *env)
{
	char *e, *token, *delim = "=";

	while(*__environ)
	{
		e = *__environ++;
		token = strtok(e, delim);

		if (str_cmp(token, env) == 0)
			return strtok(NULL, delim);
	}

	return "";
}

/**
 * get_path_cmds - gets list of
 * all commands available in PATH
 * Return: list
*/

char **get_path_cmds()
{
	int i = 0, max =100;
	char *token, **tokens = malloc(sizeof(char *) * max);
	char *path = get_env("PATH");
	char *delim = ":";

	if (tokens == NULL)
	{
		perror("malloc");
		exit(0);
	}

	if (ON_WIN == 1)
		delim = ";";
	
	token = strtok(path, delim);

	while (token !=NULL)
	{
		tokens[i] = token;

		token = strtok(NULL, delim);
		i += 1;
	}

	return (tokens);
}

/**
 * get_command_in_path - returns a command
 * in full with based on PATH
 * @cmd: the command
 * Retiurn: the command's full path
*/
char *get_command_in_path(char *cmd)
{
	char *full, **files = get_path_cmds();
	int k;

	while(*files != NULL)
	{
		full = str_cat(*files++, str_cat("/", cmd));
		k = access(full, X_OK);
		if (k == 0)
			return (full);
	}

	return (NULL);
}