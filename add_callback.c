#include "monty.h"

/**
 * add_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void add_callback(stack_t **head, unsigned int line_number)
{
	int a, b;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	a = peek(head);
	pop(head);
	b = peek(head);
	pop(head);

	push(head, b + a);
}
