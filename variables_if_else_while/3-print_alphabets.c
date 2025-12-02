#include <stdio.h>

/**
 * main - entry point
 * Description: print alphabet.
 * Return: Always 0 (Success)
 */

int main(void)
{
	char i;

	i = 'a';
	for ( ; i <= 'z'; i++)
		putchar(i);
	i = 'A';
	for ( ; i <= 'Z'; i++)
		putchar(i);
	printf("\n");
	return (0);
}

