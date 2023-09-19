#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char *command[2];

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

stack_t *push(stack_t **, int);
void pop(stack_t **);
int peek(stack_t **);
void free_stack(stack_t **);
int _getline(char **lineptr, size_t *n, FILE *file);
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void push_callback(stack_t **, unsigned int);
void pall_callback(stack_t **, unsigned int);
void pint_callback(stack_t **, unsigned int);
void pop_callback(stack_t  **, unsigned int);
void swap_callback(stack_t **, unsigned int);
void add_callback(stack_t **, unsigned int);

void (*select_callback(const char *))(stack_t **, unsigned int);

#endif
