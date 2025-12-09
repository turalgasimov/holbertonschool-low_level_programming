#include "main.h"

/**
 * print_rev - puts str rev
 * @s: str to put
 * Return: void
 */

void print_rev(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	len -= 2;

	for ( ; len >= 0; len--)
		_putchar(*(s + len));
	_putchar('\n');
}

