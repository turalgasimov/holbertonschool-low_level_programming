#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - Returns the sum of all its parameters
 * @separator: Number of arguments passed to the function
 * @n: int
 * Return: Sum of all parameters, or 0 if n == 0
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (separator == NULL)
			printf("%d", va_arg(arg, int));
		else
		{
			printf("%d%s ", va_arg(arg, int), separator);
		}

		printf("\n);
	}

	va_end(args);

	return (sum);
}

