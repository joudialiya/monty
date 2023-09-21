#include "monty.h"

/**
 * _getline - get a line from a steam [without buffer]
 * @lineptr: line ptr
 * @n: ptr to the size of lineptr
 * @file: stream
 * Return: number of chars read or -1
 */
int _getline(char **lineptr, size_t *n, FILE *file)
{
	size_t i = 0;
	int c;

	*n = 64;
	*lineptr = malloc(*n);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	while ((c = fgetc(file)) != EOF)
	{
		if (c == '\n')
			break;
		if (i + 2 > *n)
		{
			*n = 2 * *n;
			*lineptr = realloc(*lineptr, *n);
		}
		(*lineptr)[i] = c;
		++i;
	}
	if (c == EOF)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
