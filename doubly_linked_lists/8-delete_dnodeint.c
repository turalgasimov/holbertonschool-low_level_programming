#include "lists.h"
/**
 * delete_dnodeint_at_index - entry
 * @head: pointer to pointer to head;
 * @index: nth node
 * Return: 1/-1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i;

	if (*head == NULL)
		return (1);

	tmp = *head;
	if (index == 0)
	{
		if (tmp->next == NULL)
		{
			free(tmp);
			*head = NULL;
			return (1);
		}
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	for (i = 0; i < index; i++)
		tmp = tmp->next;

	if (!tmp)
		return (-1);
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	free(tmp);
	return (1);

}
