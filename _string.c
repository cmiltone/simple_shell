#include "main.h"

/**
 * str_cmp - returns 0 if two input strings are the same
 * or -1 otherwise
 *
 * @a: first string
 * @b: second string
 *
 * Return: integer, -1 or 0
*/

int str_cmp(char *a, char *b)
{
	int k = 0;

	while (a[k] != '\0' && b[k] != '\0' && a[k] == b[k])
		k += 1;
	if (a[k] == '\0' && a[k] == '\0')
		return (0);

	return (-1);
}

/**
 * str_len - gets length of input string
 *
 * @s: string
 *
 * Return: int, length of the string
 *
*/

size_t str_len(char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
		len += 1;

	return (len);
}

/**
 * str_contains - returns 1 if string contains
 * another string or 0 therwise
 *
 * @a: string
 * @b: string
 *
 * Return: 1 or 0
 *
*/

int str_contains(char *a, char *b)
{
	size_t i = 0, j, k = 0;

	if (str_len(a) == 0 || str_len(b) == 0)
		return (0);

	while (i < str_len(a))
	{
		j = 0;

		while (j < str_len(b))
		{
			if (a[i + j] == b[j])
				k += 1;
			j += 1;
		}

		if (k == str_len(b))
			return (1);

		i += 1;
	}

	return (0);
}

/**
 * str_cat - concatenetes two strings into one
 * @a: first string
 * @b: second string
 *
 * Return:  string
 **/

char *str_cat(char *a, char *b)
{
	int i = 0, j = 0;
	char *s = malloc(sizeof(char) * (str_len(a) + str_len(b)));

	if (s == NULL)
	{
		perror("malloc");
		exit(0);
	}

	while (a[i] != '\0')
	{
		s[j] = a[i];
		i += 1;
		j += 1;
	}

	i = 0;

	while (b[i] != '\0')
	{
		s[j] = b[i];
		i += 1;
		j += 1;
	}

	return (s);
}
