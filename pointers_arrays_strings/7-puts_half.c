#include "main.h"

/**
 * puts_half - puts half
 * @str: ptr to str
 * Return: void
 */

void puts_half(char *str)
{
	int len = 0;
	int i, start;

	/* Find length of string */
	while (str[len] != '\0')
		len++;

	/* Determine starting index */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* Print second half */
	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

