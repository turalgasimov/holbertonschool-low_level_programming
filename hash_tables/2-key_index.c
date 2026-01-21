#include "hash_tables.h"

/**
 * key_index - gives you the index of a key.
 * @key: key to retrieve
 * @size: size
 *
 * Return: hash value
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (!key || size <= 0)
		return (0);
	return (hash_djb2(key) % size);
}
