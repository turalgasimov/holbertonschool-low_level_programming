#include "lists.h"

/**
 * add_dnodeint - entry
 * @head: head
 * @n: int
 * Return: node
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = (dlistint_t *)malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->prev = NULL;
	new->next = *head;
	new->n = n;

	return (new);
}

