#include "monty.h"

/**
 * is_digit - check whether the input is  a digit
 *
 * Return: 1 if it is a digit 0 otherwise
 **/
int is_digit(void)
{
	int i = 0;

	if (op_arg[i] == '-' || op_arg[i] == '+')
		i++;
	while (op_arg[i])
	{
		if (isdigit(op_arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * list_len - find the number of the node in the list
 * @stack: the head of the list
 *
 * Return: the number of of nodes
 **/
int list_len(stack_t **stack)
{
	int n = 0;
	stack_t *tmp = *stack;

	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}
