#include "hash_tables.h"

/**
 * newNode - create new node;
 * Return: node
 */
hash_node_t *newNode()
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	return (node);
}

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
	char *val;
	hash_node_t *new_node;

	if (!ht || !key)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_node = ht->array[index];
	new_node = newNode();
	new_node->value = strdup(value);
	new_node->key = strdup(key);

	if (!new_node)
	{
		new_node->next = NULL;
		return (1);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
