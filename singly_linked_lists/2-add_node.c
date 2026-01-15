#include "lists.h"

/**
 * add_node - entry
 * @head: ptr
 * @str: data
 * Return: adrs / null
 */

list_t *add_node(list_t **head, const char *str)
{
	int i = 0;
	list_t *new;
	new = (list_t *)malloc(sizeof(list_t));

	new->str = strdup(str);
	new->next = *head;

	while (*str != '\0')
	{
		i++;
		str++;
	}
	
	new->len = i;

	*head = new;
	if (new->str == NULL)
		return (NULL);
	return (new);
}

