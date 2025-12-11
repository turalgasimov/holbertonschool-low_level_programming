#include "main.h"

/**
 * puts2 - puts even
 * @str: ptr to str
 * Return: void
 */

void puts2(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		str++;
		len++;
	}

	for (; len > 0; len -= 2)
	{
		_putchar(*(str - len);
	}
	_putchar('\n');
}

