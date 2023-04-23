#include "main.h"

/**
 * str_len - gets length of input string
 * 
 * @s: string
 * 
 * Return: int, length of the string
 * 
*/

int str_len(char *s)
{
  int len = 0;

  while (s[len] != '\0')
  {
    len += 1;
  }

  return (len);
}