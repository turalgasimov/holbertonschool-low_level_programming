#include <stdio.h>

/**
 * main - entry point
 * Description: print alphabet im reverse
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	i = 48;
	for ( ; i < 58; i++)
	{
		putchar(i);
		if (i == 57)
			break;
		putchar(',');
		putchar(' ');
	}
	putchar('\n');
	return (0);
}

