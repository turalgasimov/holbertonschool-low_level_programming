#include "main.h"

/**
 * print_last_digit - last dig
 * @res: num to check
 * Return: last dig
 */

int print_last_digit(int res)
{
	int last;

	last = res % 10;
	if (last < 0)
		last *= -1;

	_putchar(last + '0');
	return (last);
}
