#include "monty.h"


void queue_callback(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	g_state->mode = FIFO;
}
