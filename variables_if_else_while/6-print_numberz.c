#include <stdio.h>

/**
 * main - Entry point
 * Description: print digits
 * Return: always 0 (success)
 */

int main(void)
{
	int i;

	i = 48;
	for ( ; i < 58; i++)
		putchar(i);
	putchar('\n');
	return (0);
}

