#include "monty.h"
/**
 * free_stack - free memory alocated for stack
 * @stack: the head of the stack
 *
 * Return: nothing
 **/
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - initialize the stack to the LIFO format
 * @stack: the head of the stack
 *
 * Return: nothing
 **/
void init_stack(stack_t **stack)
{
	stack_t *init_stack;

	init_stack = malloc(sizeof(stack_t));
	if (init_stack == NULL)
		ErrorReport(Err_malloc, NULL, 0);
	init_stack->n = flag_stack;
	init_stack->next = NULL;
	init_stack->prev = NULL;
	*stack = init_stack;
}
