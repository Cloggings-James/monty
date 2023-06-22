#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number of the instruction.
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *first = *head;

	if (*head && (*head)->next)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		while (first->next)
			first = first->next;
		first->next = first->prev;
		first->prev = NULL;
		if (first->next)
			first->next->prev = first;
	}
}

