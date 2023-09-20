#include "monty.h"


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

void push_callback(stack_t **head, unsigned int line_number)
{
	int number = 0;

	if (g_state->arg == NULL || isnumber(g_state->arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
	number = atoi(g_state->arg);
	
	if (push(head, number) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_state(g_state);
		exit(EXIT_FAILURE);
	}
}
