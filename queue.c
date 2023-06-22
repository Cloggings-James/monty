#include "monty.h"

/**
 * f_queue - switches to queue mode
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addqueue - adds a node to the end of the stack (queue mode)
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *tail;

    tail = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (tail == NULL)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        while (tail->next != NULL)
            tail = tail->next;

        tail->next = new_node;
        new_node->prev = tail;
    }
}

