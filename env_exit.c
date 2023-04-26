#include "main.h"
/**
 * main - the main function of the simple shell program
 *
 * Return: 0 if success
 */

int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t line_size;
	char **args;

	while (1)
	{
		printf("$ ");
		line_size = getline(&buffer, &buffer_size, stdin);
		if (line_size == -1)
			break;
		buffer[line_size - 1] = '\0';
		args = tokenizer(buffer, " ");
		if (args == NULL)
			continue;
		if (check_builtin(args) == 0)
			execute(args);
		free(args);
	}
	free(buffer);
	return (0);
}

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
 * execute - it executes the input command
 * @args: input command and its arguments
 *
 * Return: void
 */

void execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		return;
	}
	if (child_pid == 0)
	{
		execve(args[0], args, NULL);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, WUNTRACED);
	}
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
