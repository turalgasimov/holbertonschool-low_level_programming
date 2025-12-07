#include "main.h"

/**
 * print_alphabet_x10 - print alphabet 10x
 * return 0
 */

void print_alphabet_x10(void)
{
	int i;

	i = 0;
	for ( ; i < 10; i++)
	{
		print_alphabet();
		_putchar('\n');
	}

