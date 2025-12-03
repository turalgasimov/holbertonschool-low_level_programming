#include <stdio.h>

/**
 * main - entry point
 * Description: print 2 digit combs
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;
	int k;
	int z;

	i = 48;
	for ( ; i < 56; i++)
		for (k = i + 1 ; k < 57; k++)
			for (z = k + 1; z < 58; z++)
			{
				putchar(i);
				putchar(k);
				putchar(z);
				if (i == 55)
					break;
				putchar(',');
				putchar(' ');
			}
	putchar('\n');
	return (0);
}

