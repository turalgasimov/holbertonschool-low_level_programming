#include "main.h"

/**
 * prime_check - entry point;
 * @n: int
 * @m: guess
 * Return: int
 */

int prime_check(int n, int m)
{
	if (n < 2)
		return (0);

	if (m * m > n)
		return (1);

	if (n % m == 0)
		return (0);

	return (prime_check(n, m + 1));
}

/**
 * is_prime_number - entry point
 * @n: int
 * Return: int
 */

int is_prime_number(int n)
{
	return (prime_check(n, 2));
}
