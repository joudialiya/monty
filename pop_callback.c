#include "monty.h"


/**
 * pop_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void pop_callback(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
	pop(head);
}
