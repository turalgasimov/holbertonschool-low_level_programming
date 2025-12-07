#include "main.h"

/**
 * print_last_digit - last dig
 * @res: num to check
 * Return: last dig
 */

int print_last_digit(int res)
{
	if (res < 0)
		return (-res % 10);
	else
		return (res % 10);
}
