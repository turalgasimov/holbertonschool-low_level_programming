#include "lists.h"

/**
 * sum_dlistint - entry
 * @head: head
 * Return: sum
 */

int sum_dlistint(dlistint_t *head)
{
	int sum;
	dlistint_t *node;

	if (head == NULL)
		return (0);

	sum = 0;
	node = head;
	while (node != NULL)
	{
		sum += node->n;
		node = node->next;
	}

	return (sum);
}
