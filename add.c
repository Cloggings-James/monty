#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return value.
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int len = 0, sum;

	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: Can't add, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*stack = current->next;
	free(current);
}

