#include "monty.h"


void pall_callback(stack_t **head, unsigned int line_number)
{
	if (*head)
	{
		if ((*head)->next)
			pall_callback(&((*head)->next), line_number);
		printf("%d\n", (*head)->n);
	}
}
