#include "lists.h"

/**
 * print_dlistint - entry
 * @h: head
 * Return: int
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t cnt = 0;

	while (h->next != NULL)
	{
		cnt++;

		printf("%d\n", h->n);

		h = h->next;
	}

	return (cnt);
}

