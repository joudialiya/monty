#include "monty.h"

char *command[2] = {NULL, NULL};

/**
 * main - program entry
 * @argc: args count
 * @argv: args vector
 *
 * Return: int
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *script = NULL;
	char *line = NULL;
	size_t i_line = 0;
	int line_count = 0;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	script = fopen(argv[1], "r");
	if (script == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[2]), exit(EXIT_FAILURE);
	
	while (getline(&line, &i_line, script) != -1)
	{
		void (*callback)(stack_t **, unsigned int) = NULL;
		char *opcode = strtok(line, " \t\n");
		char *arg = strtok(NULL, " \t\n");
	
	 	printf("[opcode: %s, arg: %s]\n", opcode, arg);
		line_count += 1;
		if (opcode[0] == '#')
			continue;
		callback = select_callback(opcode);
		if (callback == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction\n", line_count);
			free_stack(&stack), fclose(script), exit(EXIT_FAILURE);
		}
		command[0] = opcode;
		command[1] = arg;
		callback(&stack, line_count);
		i_line = 0, free(line), line = NULL;
	}
	free_stack(&stack), fclose(script);
	return (EXIT_SUCCESS);
}
