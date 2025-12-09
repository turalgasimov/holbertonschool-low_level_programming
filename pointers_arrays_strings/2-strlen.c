#include "main.h"

/**
 * _strlen - ret len of str
 * @s: str to check
 * Return: len of str
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\n')
	{
		s++;
		len++;
	}

	return (len - 1);

}

