#include "main.h"

/**
 * print_last_digit - last dig
 * @res: num to check
 * Return: last dig
 */

int print_last_digit(int res)
{
	int last;

	if (res < 0)
		last = (-res % 10);
	else
		last = (res % 10);
	_putchar(last + '0');
	return (last);
}
