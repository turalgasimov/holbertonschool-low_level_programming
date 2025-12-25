#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated space containing s1 + s2,
 *         or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *res;
	int len1 = 0, len2 = 0, i, j;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Get lengths */
	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	/* Allocate memory (+1 for '\0') */
	res = malloc(len1 + len2 + 1);
	if (res == NULL)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		res[i] = s1[i];

	/* Copy s2 */
	for (j = 0; j < len2; j++)
		res[i + j] = s2[j];

	/* Null terminate */
	res[i + j] = '\0';

	return (res);
}
