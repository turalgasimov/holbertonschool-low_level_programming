#include "main.h"

/**
 * _islower - checks for lower case
 * parameter @c - char to check
 * return: 1 for true or 0 for false
 */

int _islower(int c)
{
	if (c > 90 && c < 65)
		return (1);
	else
		return (0);
}

