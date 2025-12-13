#include "main.h"
#include <limits.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no digits
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	int result = 0, found = 0;
	int digit;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			digit = s[i] - '0';

			/* Prevent overflow: result = result * 10 - digit */
			if (result < (INT_MIN + digit) / 10)
				return (sign < 0 ? INT_MIN : INT_MAX);

			result = result * 10 - digit;
		}
		else if (found)
			break;
		i++;
	}

	if (!found)
		return (0);

	if (sign > 0)
	{
		if (result == INT_MIN)
			return (INT_MAX);
		result = -result;
	}

	return (result);
}
