#include "monty.h"

/**
 * push - push to the stack/tail of the dlinked list
 * @head: ptr to the list
 * @n: int
 * Return: the node or NULL
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *node = NULL;
	stack_t *current = NULL;

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

/**
 * enqueue - add to the head of the dlinked list
 * @head: ptr to the list
 * @n: int
 * Return: the node or NULL
 */
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

/**
 * pop - pop from stack/tail of the dlinked list
 * @head: ptr to the head
 */
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
}

/**
 * peek - get the int from the top of the stack/tail of the dlinked list
 * @head: ptr to the head
 * Return: the integer
 */
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

/**
 * free_stack - free double linked list
 * @head: ptr to the head
 */
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
