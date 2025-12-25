#include "main.h";
#include <stdlib.h>;

/**
 * create_array - entry point
 * @size: size
 * @c: char
 * Return: ptr / NULL
 */

char *create_array(unsigned int size, char c)
{
	char *a;
	int i;

	if (size == 0)
		return (NULL);

	a = malloc(sizeof(char) * size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		a[i] = c;
	return (a);
}
