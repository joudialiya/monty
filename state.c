#include "monty.h"

/**
 * init_state - create a progrem state
 * @filename: name of the file script
 * Return: program state
 */
state_t *init_state(const char *filename)
{
	state_t *state = NULL;
	FILE *stream = NULL;

	stream = fopen(filename, "r");
	if (stream == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename), exit(EXIT_FAILURE);
	state = malloc(sizeof(state_t));
	if (state == NULL)
		return (NULL);

	state->stack = NULL;
	state->stream = stream;
	state->line_count = 0;
	state->i_line = 0;
	state->mode = LIFO;
	state->opcode = NULL;
	state->arg = NULL;
	state->line = NULL;

	return (state);
}

/**
 * free_state - free the progrem state
 * @state: progrem state / it is globle any way
 */
void free_state(state_t *state)
{
	free_stack(&(state->stack));
	fclose(state->stream), state->stream = NULL;
	free(state->line), state->line = NULL;
	state->opcode = NULL;
	state->arg = NULL;
	free(state);
}
