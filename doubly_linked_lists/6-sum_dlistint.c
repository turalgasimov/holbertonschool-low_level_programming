#include "lists.h"

/**
 * sum_dlistint - entry
 * @head: head
 * Return: sum
 */

int sum_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return (0);

	int sum = 0;
	dlistint_t *node = head;

	while (node != NULL)
	{
		sum += node->n;
		node = node->next;
	}

	return (sum);
}
