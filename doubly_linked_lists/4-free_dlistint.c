#include "lists.h"

/**
 * free_dlistint - entry
 * @head: head
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp = head;

	if ((head == NULL) || (head->next == NULL && head->prev == NULL))
	{
		free(head);
	} else
	{
		while (tmp != NULL)
		{
			free(tmp);
			tmp = tmp->next;
		}
		return;
	}

}

