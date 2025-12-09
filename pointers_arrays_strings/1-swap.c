#include "main.h"

/**
 * swap_int - swaps int
 * @a: 1st int
 * @b: 2nd int
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

