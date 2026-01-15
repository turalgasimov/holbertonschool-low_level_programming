#include "lists.h"

/**
 * free_list - entry
 * @head: ptr to node
 */

void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

