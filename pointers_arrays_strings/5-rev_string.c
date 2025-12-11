#include "main.h"

/**
 * rev_string - rev str
 * @s: str to rev
 * Return: void
 */

void rev_string(char *s)
{
	int len = 0, i;
	char tmp;

	while (*s != '\0')
	{
		s++;
		len++;
	}

	s -= len;
	len--;

	for (i = 0; i < (len + 1) / 2; i++)
	{
		tmp = s[i];
		s[i] = s[len - i];
		s[len - i] = tmp;
	}
}

