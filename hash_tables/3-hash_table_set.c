#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: hash table you want to add or update the key/value to.
 * @key: is the key.
 * @value: is the value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *newNode, *tmp;

	if (!ht || !key)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	newNode = ht->array[index];
	if (newNode == NULL)
	{
		newNode = malloc(sizeof(hash_node_t));
		newNode->key = strdup(key);
		newNode->value = strdup(value);
		newNode->next = NULL;
		ht->array[index] = newNode;
		return (1);
	}

	tmp = newNode;
	while (tmp)
	{
		if (!strcmp(key, tmp->key))
		{
			free(tmp->value);
			tmp->value = strdup(value);
			ht->array[index] = newNode;
			return (1);
		}
		tmp = tmp->next;
	}
	newNode = malloc(sizeof(hash_node_t));

	newNode->next = ht->array[index];
	newNode->key = strdup(key);
	newNode->value = strdup(value);
	ht->array[index] = newNode;
	return (1);
}
