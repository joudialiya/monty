#include "monty.h"


void pop_callback(stack_t **head, unsigned int line_number)
{
	if(*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	pop(head);
}
