#include "lists.h"

/**
 * add_dnodeint_end - entry
 * @head: head
 * @n: int
 * Return: node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = (dlistint_t *)malloc(sizeof(dlistint_t));
	dlistint_t *tmp = *head;

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	if (tmp == NULL)
	{
		new->prev = NULL;
		*head = new;
	} else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		new->prev = tmp;
		new->prev->next = new;
	}

	new->next = NULL;
	new->n = n;

	return (new);
}

