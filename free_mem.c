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

