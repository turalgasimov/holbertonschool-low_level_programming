#include <stdio.h>

/**
 * main - entry point
 * Description: print digits of hex
 * Return: Always 0 (Success)
 */

int main(void)
{
	char i;

	i = 48;
	for ( ; i < 58; i++)
		putchar(i);
	i = 97;
	for ( ; i < 103; i++)
		putchar(i);
	putchar('\n');
	return (0);
}

