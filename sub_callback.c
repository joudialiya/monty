#include "monty.h"


void sub_callback(stack_t **head, unsigned int line_number)
{
	int a, b;

	if(*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
	a = peek(head);
	pop(head);
	b = peek(head);
	pop(head);

	push(head, b - a);
}
