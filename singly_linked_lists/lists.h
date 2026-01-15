#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct list_t
{
       char *str;
       struct list_t *next;         
};

int _putchar(char c);
size_t print_list(const list_t *h);

#endif
