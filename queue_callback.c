#include "monty.h"


/**
 * queue_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void queue_callback(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	g_state->mode = FIFO;
}
