#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @counter: Line number of the instruction.
 */
void f_swap(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	if (*head && (*head)->next)
	{
		temp = (*head)->next;
		(*head)->next = temp->next;
		if (temp->next)
			temp->next->prev = *head;
		temp->prev = NULL;
		temp->next = *head;
		(*head)->prev = temp;
		*head = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", counter);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}


