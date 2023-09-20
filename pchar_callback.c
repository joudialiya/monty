#include "monty.h"


void pchar_callback(stack_t **head, unsigned int line_number)
{
	int n = 0;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
	n = peek(head);
	if ((n < 0) || (n > 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}
