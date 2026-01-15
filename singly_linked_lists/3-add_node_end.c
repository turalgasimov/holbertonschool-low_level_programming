#include "lists.h"

/**
 * add_node_end - entry
 * @head: ptr
 * @str: str
 * Return: adrs / NULL
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = *head;
	int i = 0;

	while (new->next != NULL)
		new = new->next;

	new->next = (list_t *)malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);

	if (new->str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		i++;
		str++;
	}

	new->len = i;
	new->next = NULL;

	return (new);
}
