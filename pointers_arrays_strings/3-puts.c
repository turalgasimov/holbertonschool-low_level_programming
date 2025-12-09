#include "main.h"

/**
 * _puts - puts str
 * @str: str to put
 * Return: void
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

