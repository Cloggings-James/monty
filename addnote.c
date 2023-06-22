#include "monty.h"

/**
 * add_node_to_stack - Adds a new node to the head of the stack
 * @head: Double pointer to the head of the stack
 * @value: Value to be stored in the new node
 *
 * Return: No return value (void)
 */
void add_node_to_stack(stack_t **head, int value)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (aux != NULL)
		aux->prev = new_node;

	new_node->n = value;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

