#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to append from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* Find end of dest */
	while (dest[i] != '\0')
		i++;

	/* Append up to n characters from src */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
