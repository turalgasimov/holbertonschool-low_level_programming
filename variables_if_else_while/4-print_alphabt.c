#include <stdio.h>

/**
 * main - Entry point
 * Description: print alphabet without eq.
 * Return: always 0 (success).
 */

int main(void)
{
	char i;

	i = 'a';
	for ( ; i <= 'z'; i++)
	{
		if (i == 'e' || i == 'q')
			continue;
		putchar(i);
	}
	putchar('\n');
	return (0);

