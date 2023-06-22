#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number of the instruction.
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *last = *head;

	if (*head && (*head)->next)
	{
		while (last->next)
			last = last->next;
		last->next = last->prev;
		last->prev = NULL;
		*head = last;
	}
}

