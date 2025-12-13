#include "main.h"

/**
 * puts_half - puts half
 * @str: ptr to str
 * Return: void
 */

void puts_half(char *str)
{
	int i = 0, j;

	while (str[i]] != '\0')
	{
		i++;
	}

	if (j % 2 == 1)
	{
		j = (i - 1) / 2;
		i++;
	} else
	{
		j = i / 2;
	}

	for (; j < i; j++)
	{
		_putchar(str[j]);
	}
	_putchar('\n');
}

