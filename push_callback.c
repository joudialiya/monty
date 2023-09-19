#include "monty.h"


int isZero(char *str)
{
	while (*str != 0)
	{
		if (str[0] != '0')
			return (0);
	}
	return (1);
}

void push_callback(stack_t **head, unsigned int line_number)
{
	int number = 0;

	if (command[1] == NULL || (!isZero(command[1]) && atoi(command[1]) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
