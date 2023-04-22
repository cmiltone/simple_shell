#include "main.h"

/**
 * prompt - get user command
 *
 * Return: command
*/

char **prompt()
{
	char *cmd = NULL;
	/* Here we set to 0 so that we can let getline() function to allocate memory */
	size_t n = 0;
	char *token;
	char *delim = " \t\n\r ";
	char **args = NULL;
	int k = 0;
	char *promt_str = "#cisfun$ ";
	int j = strlen(promt_str);
  /* Here we do print the prompts */
  write(STDOUT_FILENO, promt_str, j);

  /* At this instance here, we read the user input*/
  if (getline(&cmd, &n, stdin) == -1)
		  {
		  perror("getline");
		  exit(EXIT_FAILURE);
		  }
  /* Here we remove the newline character*/

	cmd[strcspn(cmd, "\n")] = '\0';

	/* Now here we allocate memory accordingly*/
	args = malloc(sizeof(char *));

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Here the concept of tokenization comes in handy*/
	token = strtok(cmd, delim);

	while(token != NULL)
	{
		args[k] = token;
		k += 1;

		if (token == NULL)
		{
			args = realloc(args, sizeof(char *) * (k + 1));
			if (args == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	args[k] = NULL;

	/* Here we check if cmd is not NULL prior to freeing it*/
	/*if (cmd != NULL)
	{
		free(cmd);
	}freeing cmd makes arg[0] 'NULL'*/
	/* Here we free the memory that we allocated for the user's own input*/
	/*free(cmd); avoid freeing twice*/

	return (args);
}
