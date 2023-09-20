#include "monty.h"


void rotl_callback(stack_t **head, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*head && (*head)->next)
	{
		last = *head;
		while (last && last->next)
			last = last->next;

		last->prev->next = NULL;
		last->prev = (*head)->prev;
		last->next = *head;
		(*head)->prev = last;
		*head = last;
	}
}
