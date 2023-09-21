#include "monty.h"


/**
 * isnumber - is the str is a integer
 * @str: string
 * Return: i or 0
 */
int isnumber(char *str)
{
	if (*str == '-' && strlen(str) > 1)
		++str;

	while (*str != '\0')
	{
		if (isdigit(*str) == 0)
			return (0);
		++str;
	}
	return (1);
}

/**
 * push_callback - callback
 * @head: ptr to the head of the list
 * @line_number: line_number
 */
void push_callback(stack_t **head, unsigned int line_number)
{
	int number = 0;
	stack_t *node = NULL;

	if (g_state->arg == NULL || isnumber(g_state->arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
	number = atoi(g_state->arg);

	if (g_state->mode == LIFO)
		node = push(head, number);
	else
		node = enqueue(head, number);

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
}
