#include "hash_tables.h"

/**
 * push - create a new node;
 * Return: node
 */
/* hash_node_t *push()
{
} */

/**
 * update - update node;
 * Return: node
 */
/* hash_node_t *update()
{
} */

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
	hash_node_t *newNode, *head;

	if (!ht || !key)
		return (0);

	val = strdup(value);
	k = strdup(key);

	index = key_index((unsigned char *)key, ht->size);
	head = ht->array[index];
	newNode = head;

	if (newNode == NULL)
	{
		newNode = malloc(sizeof(hash_node_t));
		if (newNode == NULL)
			return (0);
		newNode->key = k;
		newNode->value = val;
		newNode->next = NULL;
		return (1);
	}

	if (newNode != NULL)
	{
		newNode = malloc(sizeof(hash_node_t));
		newNode->key = k;
		newNode->value = val;
		newNode->next = head;
		head = newNode;
		return (1);
	}
}
