#include "main.h"

/**
 * tokenizer - to tokenize the input buffer
 * @str: input buffer
 * @delimiter: delimiter character
 *
 * Return: array of tokens
 */

char **tokenizer(char *str, const char *delimiter)
{
	int i = 0;
	char **tokens = NULL;
	char *token = NULL;

	if (str == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
		return (NULL);

	token = strtok(str, delimiter);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * check_builtin - check if the input command is built-in
 * @args: input the command and its arguments
 *
 * Return: 1 if the input command is built-in, else 0
 */

int check_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			int exit_status = atoi(args[1]);

			exit(exit_status);
		}
		else
	{
		exit(0);
	}
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	return (0);
}

/**
 * print_env - to print the current environment
 *
 * Return: void
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
