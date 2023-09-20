#include "monty.h"


void stack_callback(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	g_state->mode = LIFO;
}
