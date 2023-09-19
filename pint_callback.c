#include "monty.h"


void pint_callback(stack_t **head, unsigned int line_number)
{
	if(*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", peek(head));
}
