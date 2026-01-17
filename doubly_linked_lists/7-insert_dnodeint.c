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
	dlistint_t *tmp, *prev, *next, *new;
	unsigned int i, len;

	tmp = *h;
	len = 1;
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	new = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	if (idx == 0)
	{
		if (*h == NULL)
		{
			new->n = n;
			new->prev = NULL;
			new->next = NULL;
			*h = new;
			return (new);
		}

		new->n = n;
		new->prev = NULL;
		new->next = *h;
		new->next->prev = new;
		*h = new;
		return (new);
	}

	tmp = tmp->prev;
	if (idx == (len))
	{
		new->n = n;
		new->next = NULL;
		new->prev = tmp;
		tmp->next = new;
		return (new);
	}

	tmp = *h;
	for (i = 0; i < idx; i++)
	{
		if (tmp == NULL)
		{
			free(new);
			return (NULL);
		}
		tmp = tmp->next;
	}

	prev = tmp->prev;
	next = tmp;

	new->n = n;
	new->prev = prev;
	new->prev->next = new;

	new->next = next;
	new->next->prev = new;

	return (new);
}
