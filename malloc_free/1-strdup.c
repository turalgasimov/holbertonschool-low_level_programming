#include "main.h"
#include <stdlib.h>

/**
 * _strdup - entry point
 * @str: char
 * Return: ptr / NULL
 */

char *_strdup(char *str)
{
	char *a;
	int size = 0, i;

	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		str++;
		size++;
	}

	str -= size;

	a = malloc(size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		a[i] = str[i];

	return (a);
}
