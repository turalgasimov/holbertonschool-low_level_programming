#include <stdio.h>

/**
 * main - Entry point
 * Description: print digits
 * Return: always 0 (success)
 */

int main(void)
{
	int i;

	i = 0;
	for ( ; i < 10; i++)
		printf("%d", i);
	putchar('\n');
	return (0);
}

