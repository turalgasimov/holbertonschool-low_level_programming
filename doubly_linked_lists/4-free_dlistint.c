#include "lists.h"

/**
 * free_dlistint - entry
 * @head: head
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp = head;

	if ((head->next == NULL && head->prev == NULL)  || head == NULL)
	{
		free(head);
		return;
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

