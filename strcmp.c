/**
 * str_cmp - returns 0 if two input strings are the same
 * or -1 otherwise
 * 
 * @a: first string
 * @b: second string
 * 
 * Return: integer, -1 or 0
*/

int str_cmp(char * a, char *b)
{
  int k = 0;

  while (a[k] != '\0' && b[k] != '\0' && a[k] == b[k])
		k += 1;
	if (a[k] == '\0' && a[k] == '\0')
		return (0);

	return (-1);
}
