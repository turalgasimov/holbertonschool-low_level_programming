#include "main.h"

/**
 * print_alphabet_x10 - print alphabet 10x
 * return 0
 */

void print_alphabet_x10(void)
{
	char c;
	int i;

	i = 0;
	while (i < 10)
	{
		c = 'a';
		for ( ; c < 'z'; c++)
			_putchar(c);
		_putchar('\n');
		i++;
	}
}

