#include "monty.h"


void pstr_callback(stack_t **head, unsigned int line_number)
{
	if (*head)
	{
		if ((*head)->next)
			pstr_callback(&((*head)->next), line_number);
		printf("%d\n", (*head)->n);
	}
}
