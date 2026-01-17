#include "lists.h"

int main() {
        dlistint_t *head;
        head = NULL;

        add_dnodeint(&head, 10);
        add_dnodeint(&head, 22);
        printf("-> %zu elements\n", print_dlistint(head));
        return (0);

}