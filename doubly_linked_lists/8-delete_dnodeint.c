#include "lists.h"
/**
 * delete_dnodeint_at_index - entry
 * @h: pointer to pointer to head;
 * @idx: nth node
 * Return: 1/-1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	tmp = *head;
	if (index == 0)
	{
		if (!tmp)
			return(1);
		*head = tmp->next;
		free(tmp);
		return (1);		
	}

	for (i = 0; i < index; i++)
		tmp = tmp->next;

	if (!tmp)
		return (-1);
	else
	{
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		free(tmp);
		return (1);
	}
}
