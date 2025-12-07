#include "main.h"

/**
 * times_table - 9 times table
 * Return: void
 */

void times_table(void)
{
	int a, b, c, d1, d2;

	for (a = 0; a < 10; a++)
		for (b = 0; b < 10; b++)
		{
			c = a * b;
			if (c > 9)
			{
				d1 = c % 10;
				d2 = c / 10;
				_putchar(',');
				_putchar(' ');
				_putchar(d1 + '0');
				_putchar(d2 + '0');
			} else
			{
				if (b == 9)
				{
					_putchar(',');
					_putchar(' ');
					_putchar('\n');
				}
				_putchar(c + '0');
			}
		}
	_putchar('\n');
}
