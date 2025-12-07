#include "main.h"

/**
 * _islower - entry point
 * Description: checks for lowercase
 * @c: - char to check
 * Return: 1 if the car is lowercase, 0 otherwise
 */

int _islower(int c)
{
	if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}

