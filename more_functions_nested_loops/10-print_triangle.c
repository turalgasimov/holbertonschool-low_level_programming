#include "main.h"

/**
 * print_triangle - prints a triangle
 * @size: size of the triangle
 */
void print_triangle(int size)
{
	int i, space, hash;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			for (space = size - i; space > 0; space--)
				_putchar(' ');

			for (hash = 0; hash < i; hash++)
				_putchar('#');

			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
