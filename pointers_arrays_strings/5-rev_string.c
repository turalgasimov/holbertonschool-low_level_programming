#include "main.h"

/**
 * rev_string - rev str
 * @s: str to rev
 * Return: void
 */

void rev_string(char *s)
{
	int len = 0, i = 0;
	char *p = s;

	while (*p != '\0')
	{
		p++;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
}

