#include "lists.h"

/**
 * print_list - entry
 * @h: list
 * Return: size
 */

size_t print_list(const list_t *h)
{
	list_t lst = h;
	size_t i = 0;
	char *s;

	while (*lst->next != NULL)
	{
		*s = *lst->str;
		if (s == NULL)
			*s = "(nil)";
		printf("[%d] %s", sizeof(*s), *s);
		i++;
	}

	return (i);
}

