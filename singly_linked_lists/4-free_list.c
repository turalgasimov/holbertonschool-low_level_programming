#include "lists.h"

/**
 * free_list - entry
 * @head: ptr to node
 */

void free_list(list_t *head)
{
	while (head-> next != NULL)
		free(head);
}

