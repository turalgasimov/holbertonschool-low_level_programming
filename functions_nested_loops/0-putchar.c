#include <stdio.h>

/**
 * main - Entry point
 * Description: prints putchar
 * Return: Alwasy (0) (Success)
 */

int main(void)
{
	char msg[] = "_putchar";
	int i;
	
	while (msg[i] != '\0')
	{
		putchar(msg[i]);
		i++;
	}
	putchar('\n');
	return (0);
}

