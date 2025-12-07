#include "main.h"

/**
 * add - add 2 ints
 * @a: 1st int
 * @b: 2nd int
 * Return: result
*/

int add(int a, int b)
{
	int sum;

	sum = a + b;
	if (sum < 0)
	{
		_putchar('-');
		sum = -sum;
	}
	if (sum >= 10)
	{
		_putchar((sum / 10) + '0');
	}
	_putchar((sum % 10) + '0');
	_putchar('\n');
}

