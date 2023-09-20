#include "monty.h"

state_t *init_state(char *filename);
{
	statt_t *s = NULL;
	FILE *stream = fopen(filename, "r");
	
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	s = malloc(sizeof(state_t));
	if (s == NULL)
	{
		
	}
	s->stream = stream;
	s->i_line = 0;
	s->mode = LIFO;
	s->opcode = NULL;
	s->arg = NULL;

	return (s);
}
