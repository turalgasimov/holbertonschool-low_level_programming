#include <unistd.h>

/***
 * print_alphabet = prints alphabet
 * Return: nothing
 */

void print_alphabet(void)
{
	int i;

	i = 97;
	for ( ; i < 123; i++)
		_putchar(i);
	_putchar('\n');
