#include "main.h"

/**
 * print_sign - prints sign
 * @n: num to check
 * Return: 0, 1, -1
 */

int print_sign(int n)
{
	int res;

	if (n > 0)
	{
		_putchar('+');
		res = 1;
	} else if (n == 0)
	{
		_putchar('0');
		res = 0;
	} else if (n < 0)
	{
		_putchar('-');
		res = -1;
	}

	return (res);
}

