#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);

	while (s[len])
		len++;
	return (len);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to new string, NULL if fails
 */
char *_strdup(char *str)
{
	int len, i;
	char *copy;

	if (!str)
		return (NULL);

	len = _strlen(str);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);

	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog, NULL if failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);

	d->name = _strdup(name);
	if (name && !d->name) /* malloc failed */
	{
		free(d);
		return (NULL);
	}

	d->owner = _strdup(owner);
	if (owner && !d->owner)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;

	return (d);
}
