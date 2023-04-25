#include "main.h"

/**
 * _getline - readline
 * @lineptr: where to write the string
 * @n: size of the string
 * @stream: file descriptor
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
  char *buff = malloc(sizeof(char *) * *n);
  int k;

  if (buff == NULL)
    return (-1);

  if (stream != NULL)
    k = read(STDIN_FILENO, buff, *n);

  if (k  == 0)
    return (-1);

  if (str_len(buff) > 0)
  {
    buff[str_len(buff)] = '\0';

    lineptr[0] = buff;
  }
  
  return str_len(buff);
}
