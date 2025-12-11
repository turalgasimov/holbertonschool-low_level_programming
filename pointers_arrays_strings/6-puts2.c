#include "main.h"

/**
 * puts2 - puts even
 * @str: ptr to str
 * Return: void
 */

void puts2(char *str)
{
	while (1)
	{
		_putchar(*str);
		if (*str == '\0')
			break;
		str += 2;
	}
}

