#include "main.h"

/**
 * _getline - readline
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
  char *buff = malloc(sizeof(char *) * *n);

  if (buff == NULL)
    return (-1);

  if (stream != NULL)
    read(STDIN_FILENO, buff, *n);

  buff[str_len(buff)] = '\0';

  lineptr[0] = buff;
  
  return 1;
}
