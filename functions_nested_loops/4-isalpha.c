#include "main.h"

/**
 * _isalpha - entry point
 * @c: char to check
 * Return: 1 if char is letter, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

