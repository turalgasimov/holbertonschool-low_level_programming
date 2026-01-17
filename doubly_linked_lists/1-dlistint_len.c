#include "lists.h"

/**
 * dlistint_len - entry
 * @h: head
 * Return: int
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t cnt = 0;

	tmp = h;

	while (tmp != NULL)
	{
		cnt++;
		tmp = tmp->next;
	}

	return (cnt);
}
