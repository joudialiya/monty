#include "monty.h"


/**
 * pstr_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void pstr_callback(stack_t **head, unsigned int line_number)
{
	stack_t *last = NULL;

	(void)line_number;
	last = *head;
	while (last && last->next)
		last = last->next;
	while (last && last->n > 0 && last->n < 128)
	{
		printf("%c", last->n);
		last = last->prev;
	}
	printf("\n");
}
