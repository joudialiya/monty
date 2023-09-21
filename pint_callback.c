#include "monty.h"


/**
 * pint_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void pint_callback(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", peek(head));
}
