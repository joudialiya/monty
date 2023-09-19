#include "monty.h"


void pchar_callback(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 177)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
