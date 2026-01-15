#include "lists.h"

/**
 * print_list - entry
 * @h: list
 * Return: size
 */

size_t print_list(const list_t *h)
{
	const list_t *lst = h;
	int i = 0;
	str s;

	while (lst != NULL)
	{
		s = lst->str;
		if (s == NULL)
			s = "(nil)";
		printf("[%d] %s", lst->len, s);
		i++;
		lst = lst->next;
	}

	return (i);
}
