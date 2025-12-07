#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character \ is printed
 */
void print_diagonal(int n)
{
	int i, space;

	if (n > 0)
	{
		for (i = 0; i < n; i++)
		{
			for (space = 0; space < i; space++)
				_putchar(' ');

			_putchar('\\');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
