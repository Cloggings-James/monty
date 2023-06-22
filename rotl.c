#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 * Return: no return
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    stack_t *tmp = *head;
    stack_t *aux = (*head)->next;

    aux->prev = NULL;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    (*head) = aux;
}

