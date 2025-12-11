#include "main.h"

/**
 * rev_string - rev str
 * @s: str to rev
 * Return: void
 */

void rev_string(char *s)
{
	int len = 0;
	char *p = s;

	while (*p != '\0')
	{
		p++;
		len++;
	}

	len--;

	for ( ; len >= 0; len--)
		_putchar(*(s + len));
	_putchar('\n');
}

