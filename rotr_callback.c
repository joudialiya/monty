#include "monty.h"


void rotr_callback(stack_t **head, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*head && (*head)->next)
	{
		last = *head;
		while (last && last->next)
			last = last->next;

		(*head)->prev = last;
		last->next = *head;
		*head = (*head)->next;
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
	}
}
