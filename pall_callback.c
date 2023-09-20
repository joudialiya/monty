#include "monty.h"


void pall_callback(stack_t **head, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	last = *head;
	while (last)
	{
		printf ("%d\n", last->n);
		last = last->next;
	}
}
