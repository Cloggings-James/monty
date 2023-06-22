#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/* Structs */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct bus_s
{
    FILE *file;
    char *content;
    stack_t *stack;
    int lifo;
} bus_t;

extern bus_t bus;

/* Function Prototypes */
int execute(stack_t **stack, char *content, unsigned int counter, FILE *file);
void free_stack(stack_t *stack);

#endif /* MONTY_H */

