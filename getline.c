#include "monty.h"

int _getline(char **lineptr, size_t *n, FILE *file)
{
	int i = 0;
	int c;
	
	*n = 4096;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			break;
		(*lineptr)[i] = c;
		++i;
	}
	if (c == EOF)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
