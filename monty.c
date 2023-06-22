#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        bus.content = content;
        counter++;
        if (read_line > 0)
        {
            execute(&stack, content, counter, file);
        }
        free(content);
    }
    free_stack(stack);
    fclose(file);
    return (0);
}

/**
 * execute - execute Monty bytecode commands
 * @stack: double pointer to the stack
 * @content: current line of Monty bytecode
 * @counter: line number of the command being executed
 * @file: Monty bytecode file
 * Return: 0 on success, 1 on failure
 */
int execute(stack_t **stack, char *content, unsigned int counter, FILE *file)
{
    /* Add your command execution logic here */
    (void)stack;
    (void)content;
    (void)counter;
    (void)file;
    return (0);
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *current = stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

