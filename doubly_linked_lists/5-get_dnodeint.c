#include "lists.h"

/**
 * get_dnodeint_at_index - entry
 * @head: head
 * @index: nth node
 * Return: node
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node = head;
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (node == NULL)
		{
			break;
		}

		node = node->next;
	}

	return (node);
}
