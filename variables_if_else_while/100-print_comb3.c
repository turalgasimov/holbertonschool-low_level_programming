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

	i = 48;
	for ( ; i < 57; i++)
		for (k = i + 1 ; k < 58; k++)
		{
			putchar(i);
			putchar(k);
			if (i == 56)
				break;
			putchar(',');
			putchar(' ');
		}
	putchar('\n');
	return (0);
}

