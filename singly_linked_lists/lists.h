#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct list
{
       char *str;
       struct list *next;         
} list_t;

int _putchar(char c);
size_t print_list(const list_t *h);

#endif
