#include "lists.h"

/**
 * add_node - entry
 * @head: ptr
 * @str: data
 * Return: adrs / null
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new = (list_t *)malloc(sizeof(list_t));

	new->str = strdup(*str);
	new->next = *head;

	*head = new;
	return (new);
}

