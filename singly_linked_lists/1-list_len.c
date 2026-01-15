#include "lists.h"

/**
 * list_len - entry
 * @h: list
 * Return: size
 */

size_t list_len(const list_t *h)
{
	const list_t *lst = h;
	int i = 0;

	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}

	return (i);
}

