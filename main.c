#include "monty.h"

state_t *g_state = NULL;

/**
 * main - program entry
 * @argc: args count
 * @argv: args vector
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	g_state = init_state(argv[1]);

	while (_getline(&(g_state->line), &(g_state->i_line), g_state->stream) != -1)
	{
		void (*callback)(stack_t **, unsigned int) = NULL;

		g_state->opcode = strtok(g_state->line, " \r\t\n");
		g_state->arg = strtok(NULL, " \r\t\n");
#ifdef DEBUG
		printf("[opcode: %s, arg: %s]\n", g_state->opcode, g_state->arg);
#endif
		g_state->line_count += 1;
		if (g_state->opcode && g_state->opcode[0] != '#')
		{
			callback = select_callback(g_state->opcode);
			if (callback == NULL)
			{
				fprintf(stderr, "L%i: ", g_state->line_count);
				fprintf(stderr, "unknown instruction %s\n", g_state->opcode);
				free_state(g_state);
				exit(EXIT_FAILURE);
			}
			callback(&(g_state->stack), g_state->line_count);
		}
		g_state->i_line = 0;
		free(g_state->line);
		g_state->line = NULL;
		g_state->opcode = NULL;
		g_state->arg = NULL;
	}
	free_state(g_state);
	return (EXIT_SUCCESS);
}
