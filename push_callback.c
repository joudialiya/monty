#include "monty.h"


int isnumber(char *str)
{
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

	if (command[1] == NULL || isnumber(command[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	number = atoi(command[1]);
	
	if (push(head, number) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
