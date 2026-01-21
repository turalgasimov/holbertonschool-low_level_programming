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

	index = key_index(key, sizeof(ht));

	hash_node_t *newNode = (hash_node_t *)malloc(sizeof(hash_node_t));
		if (newNode == NULL)
			return (0);
	if (!(ht->array[index]))
	{
		newNode->next = ht->array[index];
		ht->array[index] = newNode;
	}
	else
		newNode->next = NULL;
	newNode->key = strdup(key);
	newNode->value = strdup(value);

	return (1);
}
