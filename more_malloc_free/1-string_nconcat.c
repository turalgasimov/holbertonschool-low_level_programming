#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to copy from s2
 *
 * Return: pointer to newly allocated memory containing s1
 *         followed by n bytes of s2, null terminated,
 *         or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *res;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Get length of s1 */
	while (s1[len1] != '\0')
		len1++;

	/* Get length of s2 */
	while (s2[len2] != '\0')
		len2++;

	/* If n >= len2, use whole s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory (+1 for '\0') */
	res = malloc(len1 + n + 1);
	if (res == NULL)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		res[i] = s1[i];

	/* Copy first n bytes of s2 */
	for (j = 0; j < n; j++)
		res[i + j] = s2[j];

	/* Null terminate */
	res[i + j] = '\0';

	return (res);
}
