#include <stdio.h>

/**
 * main - Entry point
 * Description: prints putchar
 * Return: Alwasy (0) (Success)
 */

int main(void)
{
	char msg[] = "_putchar";
	int i = 0;

	while (msg[i] != '\0')
	{
		_putchar(msg[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}

