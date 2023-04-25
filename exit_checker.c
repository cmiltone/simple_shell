#include "main.h"
/**
 * teamstrncpy - Here it copies a string
 * @dest: this is the destination of the string
 * @src: this is the source string.
 * @n: The maximum number of bytes to be used here.
 *
 * Return: the pointer is returned to the destination string
 */

char *teamstrncpy(char *dest, char *src, size_t n)
{
	char *s = dest;
	size_t i, j;
	/*
	 * here it copies characters from the source to destination until
	 * n or rather '\0' is reached
	 */
	for (i = 0; src[i] != '\0' && i < n - 1; i++)
		dest[i] = src[i];

	/*
	 * so incase the source is less than n, we fill the remaining space
	 * sequence in desination with null bytes
	 */
	if (_strlen(src) < n)
		for (j = _strlen(src); j < n; j++)
			dest[j] = '\0';

	return (s);
}
/**
 * _strlen - The function here calculates the length of a string
 * @s: This is the string to be calculated
 *
 * Return: This is the length of the string
 */
size_t _strlen(char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * teamstrncat - Here it concatenates 2 strings
 * @dest: this is the destination string.
 * @src: the source of the string.
 * @n: this is the maximum number of bytes that can be used.
 *
 * Return: This is the pointer to the destination string.
 */

char *teamstrncat(char *dest, char *src, int n)
{
	char *s = dest;
	int i = 0, j = 0;

	/* Here, we find the end of the destination string */
	while (dest[i] != '\0')
		i++;

	/*
	 * this step, we concatenate characters from the source to destination
	 * until n or '\0' is reached
	 */
	for (j = 0; src[j] != '\0' && j < n; j++, i++)
		dest[i] = src[j];

	/*
	 * if the source is less than n, we add a null byte at the ened of
	 * the string
	 */
	if (_strlen(src) < (size_t)n)
		dest[i] = '\0';

	return (s);
}

/**
 * teamstrchr - this locates a character in a string
 * @s: this is the string to be searched
 * @c: This is the character to be located.
 * Return: This is the pointer to the first occassion where the character c
 * in the strings is spotted., or NULL if the character is not found.
 */
char *teamstrchr(char *s, char c)
{
	/*
	 * this loops through out the string untiil c is found or end
	 * of string is reached
	 */
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
