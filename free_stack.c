#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @stack: Pointer to the head of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current, *next_node;

	current = stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

