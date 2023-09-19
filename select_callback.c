#include "monty.h"

void (*select_callback(const char *opcode))(stack_t **, unsigned int)
{
	instruction_t list[] = {
		{"push", push_callback},
		{"pall", pall_callback},
		{"pint", pint_callback},
		{"pop", pop_callback},
		{"swap", swap_callback},
		{"add", add_callback},
		{"nop", add_callback},
		{NULL, NULL}
	};
	int i = 0;

	while (list[i].opcode != NULL)
	{
		if (strcmp(list[i].opcode, opcode) == 0)
			return (list[i].f);
		++i;
	}
	return (NULL);
}
