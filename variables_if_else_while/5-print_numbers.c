#include <stdio.h>

/**
 * main - Entry point
 * Description: print digits
 * Return: always 0 (success)
 */

int main(void)
{
	char i;

	i = 0;
	for ( ; i < 10; i++)
		putchar(i);
	putchar('\n');
	return (0);
}

