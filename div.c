#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @stack: Pointer to the stack head.
 * @line_number: Line number.
 * Return: No return value.
 */
void divide_top_two_elements(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    int len = 0, result;

    while (current)
    {
        current = current->next;
        len++;
    }

    if (len < 2)
    {
        fprintf(stderr, "L%d: Can't div, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: Division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    result = current->next->n / current->n;
    current->next->n = result;
    *stack = current->next;
    free(current);
}

