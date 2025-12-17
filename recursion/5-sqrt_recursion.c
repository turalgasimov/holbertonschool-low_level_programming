#include "main.h"

/**
 * sqrt_check - entry point;
 * @n: int
 * @m: guess
 * Return: int
 */

int sqrt_check(int n, int m)
{
	if (m * m == n)
		return (m);

	if (m * m > n)
		return (-1);

	return (sqrt_check(n, m + 1));
}

/**
 * _sqrt_recursion - entry point
 * @n: int
 * Return: int
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_check(n, 0));
}
