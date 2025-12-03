#include <stdio.h>

/**
 * main - entry point
 * Description: print alphabet.
 * Return: Always 0 (Success)
 */

int main(void)
{
	char a;
	char i;

	a = 'a';
	for (i = a; i <= 'z'; i++)
		putchar(i);
	putchar('\n');
	return (0);
}

