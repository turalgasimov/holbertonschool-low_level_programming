#include "dog.h"

/**
 * free_dog - frees a dog
 * @d: pointer to the dog to free
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	/* Free dynamically allocated name and owner */
	free(d->name);
	free(d->owner);

	/* Free the struct itself */
	free(d);
}
