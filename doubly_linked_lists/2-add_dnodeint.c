#include "lists.h"

/**
 * add_dnodeint - entry
 * @head: head
 * @n: int
 * Return: node
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new = (dlistint_t *)malloc(sizeof(dlistint_t));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	if (*head == NULL)
	{
		new->next = NULL;
	} else
	{
		new->next = *head;
		new->next->prev = new;
	}

	new->prev = NULL;
	new->n = n;

	*head = new;

	return (new);
}

