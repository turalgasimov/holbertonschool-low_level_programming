#include <stdio.h>

/**
 * main - entry point
 * Description: print alphabet im reverse
 * Return: Always 0 (Success)
 */

int main(void)
{
	char i;

	i = 'z';
	for ( ; i >= 'a'; i--)
		putchar(i);
	putchar('\n');
	return (0);
}

