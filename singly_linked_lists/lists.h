#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct l - linkedlist
 * @str: string
 * @len: length
 * @next: next node
 * Description: struct for list
 */
typedef struct l
{
	char *str;
	unsigned int len;
	struct l *next;
} list_t;

int _putchar(char c);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);

#endif
