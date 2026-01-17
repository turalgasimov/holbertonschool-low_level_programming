#include "lists.h"

/**
 * print_dlistint - entry
 * @h: head
 * Return: int
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *tmp;
	size_t cnt = 0;

	tmp = h;

	while (tmp != NULL)
	{
		cnt++;

		printf("%d\n", tmp->n);

		tmp = tmp->next;
	}

	return (cnt);
}

