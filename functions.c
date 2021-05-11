#include "monty.h"
/**
 * push_monty - function to push to stack
 * @stack: the head of the stack
 * @op_arg: the argument of the operation
 *
 * Return: nothing
 **/
void push_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		ErrorReport(Err_malloc, NULL, line_no);
	if (op_arg == NULL || stack == NULL || !is_digit())
		ErrorReport(Err_user2, NULL, line_no);
	new_node->n = atoi(op_arg);
	
	if (*stack == NULL)
	{
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
		return; 
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall_monty - function to print all values
 * @stack: the head of the stack
 * @line_no: the line number
 *
 * Return: nothing
 **/
void pall_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *cur;
	(void) line_no;

	if(*stack)
	{
		cur = *stack;
		while (cur)
		{
			printf("%d\n", cur->n);
			cur = cur->next;
		}
	}
	
}
