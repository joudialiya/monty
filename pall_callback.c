#include "monty.h"


/**
 * pall_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void pall_callback(stack_t **head, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	last = *head;
	while (last && last->next)
	{
		last = last->next;
	}
	while (last)
	{
		printf("%d\n", last->n);
		last = last->prev;
	}
}
