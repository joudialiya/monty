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
		{"nop", nop_callback},
		{"sub", sub_callback},
		{"div", div_callback},
		{"mul", mul_callback},
		{"mod", mod_callback},
		{"pchar", pchar_callback},
		{"pstr", pstr_callback},
		{"rotl", rotl_callback},
		{"rotr", rotr_callback},
		{"stack", stack_callback},
		{"queue", queue_callback},
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
