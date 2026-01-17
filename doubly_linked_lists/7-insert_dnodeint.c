#include "lists.h"

/**
 * insert_dnodeint_at_index - entry
 * @h: pointer to pointer to head;
 * @idx: nth node
 * @n: int
 * Return: node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;
	unsigned int i;

	new = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->prev = NULL;
		new->next = *h;
		if (*h != NULL)
			(*h)->prev = new;
		*h = new;
		return (new);
	}

	tmp = *h;
	for (i = 0; i < idx && tmp != NULL; i++)
		tmp = tmp->next;

	if (i != idx)
	{
		free(new);
		return (NULL);
	}

	new->next = tmp;
	if (tmp != NULL)
	{
		new->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = new;
		tmp->prev = new;
	} else
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		new->next = NULL;
	}

	return (new);
}
