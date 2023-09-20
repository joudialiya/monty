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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	
	while (_getline(&line, &i_line, script) != -1)
	{
		void (*callback)(stack_t **, unsigned int) = NULL;
		char *opcode = strtok(line, " \r\t\n");
		char *arg = strtok(NULL, " \r\t\n");
#ifdef DEBUG	
	 	printf("[opcode: %s, arg: %s]\n", opcode, arg);
#endif
		line_count += 1;
		if (opcode == NULL || opcode[0] == '#')
			continue;
		callback = select_callback(opcode);
		if (callback == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_count, opcode);
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
