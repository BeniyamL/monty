#include "monty.h"
/**
 * push_monty - function to push to stack
 * @stack: the head of the stack
 * @line_no: the argument of the operation
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

	if (*stack)
	{
		cur = *stack;
		while (cur)
		{
			printf("%d\n", cur->n);
			cur = cur->next;
		}
	}
}
/**
 * pint_monty - function to print the value at the top of the stack
 * @stack: the head of the stack
 * @line_no: the number of line of the monty file
 *
 * Return: nothing
 **/
void pint_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *top = *stack;

	if (top == NULL || stack == NULL)
		ErrorReport(Err_empty, NULL, line_no);
	printf("%d\n", top->n);
}
/**
 * pop_monty - removes the top element
 * @stack: the head of the stack
 * @line_no: the number of line of the monty file
 *
 * Return: nothing
 **/
void pop_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *cur = *stack;

	if (cur == NULL || stack == NULL)
		ErrorReport(Err_empty_pop, NULL, line_no);
	if (cur->next)
	{
		cur->next->prev = cur->prev;
		*stack = cur->next;
	}
	else
	{
		*stack = NULL;
	}
	free(cur);
}
/**
 * swap_monty - swaps the top two elements of the stack
 * @stack: the head of the stack
 * @line_no: the line number of the monty file
 *
 * Return: nothing
 **/
void swap_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *temp = *stack;
	int n = 0, val;

	n = list_len(stack);
	if (n < 2)
		ErrorReport(Err_swap_len, NULL, line_no);
	val = temp->n;
	temp->n = temp->next->n;
	temp->next->n = val;
	*stack = temp;
}
