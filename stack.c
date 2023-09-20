#include "monty.h"

stack_t *push(stack_t **head, int n)
{
	stack_t *node = NULL;
	stack_t * current = NULL;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = NULL;
	current = *head;
	while (current && current->next)
		current = current->next;
	if (current == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}
	node->prev = current;
	current->next = node;
	return (node);
}
stack_t *enqueue(stack_t **head, int n)
{
	stack_t *node = NULL;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);
	node->n = n;
	node->next = *head;
	node->prev = NULL;
	if (*head)
	{
		node->prev = (*head)->prev;
		(*head)->prev = node;
	}
	*head = node;
	return (node);
}
void pop(stack_t **head)
{
	stack_t *current = NULL;

	if (head == NULL)
		return;
	current = *head;
	while (current && current->next)
		current = current->next;
	if (current == NULL)
			return;
	if (current->prev)
		current->prev->next = current->next;
	else
		*head = NULL;
	free(current);
	return;
}

int peek(stack_t **head)
{
	stack_t *current = NULL;

	if (head == NULL)
		return (0);
	current = *head;
	while (current && current->next)
		current = current->next;
	if (current == NULL)
		return (0);
	return (current->n);
}

void free_stack(stack_t **head)
{
	stack_t *current = NULL;

	current = *head;
	while (current)
	{
		stack_t *next = current->next;
		
		free(current);
		current = next;
	}
	*head = NULL;
}
