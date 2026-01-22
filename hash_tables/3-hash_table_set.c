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
	char *val, *k;
	hash_node_t *newNode;

	if (!ht || !key)
		return (0);

	val = strdup(value);
	k = strdup(key);

	index = key_index((unsigned char *)key, ht->size);
	newNode = ht->array[index];
	newNode = malloc(sizeof(hash_node_t));
	newNode->key = k;
	newNode->value = val;

	if (newNode == NULL)
	{
		newNode->next = NULL;
		return (1);
	}

	newNode->next = ht->array[index];
	ht->array[index] = newNode;

	return (1);
}
