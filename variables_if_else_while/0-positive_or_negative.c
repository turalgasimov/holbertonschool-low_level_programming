#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */

/**
 * main - Entry point
 * Description: find the sign.
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{
		printf("%l is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%l is zero\n", n);
	}
	else
	{
		printf("%l is negative\n", n);
	}
	return (0);
}
