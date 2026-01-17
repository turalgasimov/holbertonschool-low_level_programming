#include "lists.h"

int main() 
{
        dlistint_t *head;
        head = NULL;

        add_dnodeint_end(&head, 10);
        add_dnodeint_end(&head, 22);
        printf("-> %zu elements\n", print_dlistint(head));
        return (0);
}
