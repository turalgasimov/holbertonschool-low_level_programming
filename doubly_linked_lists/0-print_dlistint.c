#include "lists.h"

/**
 * print_dlistint - entry
 * @h: head
 * Return: int
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *tmp;

	tmp = h;
	size_t cnt = 0;

	while (tmp->next != NULL)
	{
		cnt++;

		printf("%d\n", tmp->n);

		tmp = tmp->next;
	}

	return (cnt);
}

