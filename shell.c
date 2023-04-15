#include "main.h"

/**
 * shell - starts an interrractive shell
*/

void shell(char* filename)
{
	char *cmd = NULL;
	char *args[] = {NULL};
	size_t n = 10;
  // char *str = strcat(filename, ":");
  
  printf("#cisfun$ ");

  getline(&cmd, &n, stdin);

  cmd[strlen(cmd) - 1] = '\0';

  int k = execve(cmd, args, NULL);
  if (k == -1)
  {
    perror(filename);
  }
}