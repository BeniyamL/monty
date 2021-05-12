#include "monty.h"

/**
 * add_monty - function to add the top two elements of the stack
 * @stack: the head of the stacck
 * @line_no: the line number of the monty file
 *
 * Return: nothing
 **/
void add_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;
	int sum, n = 0, val, val2;

	n = list_len(stack);
	if (n < 2)
		ErrorReport_2(Err_add_len, line_no);
	val = tmp->n;
	val2 = tmp->next->n;
	sum = val + val2;
	tmp->next->n = sum;
	tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);
}
/**
 * nop_monty - function to do nothing
 * @stack: the head of the stack
 * @line_no: the number of the lines of the monty
 *
 * Return: nothing
 **/
void nop_monty(stack_t **stack, unsigned int line_no)
{
	(void) stack;
	(void) line_no;
}
/**
 * sub_monty - subtracts the top elements of the stack from the second top
 * @stack: the head of the stack
 * @line_no: the nubmer of the lines of the monty file
 *
 * Return: nothing
 **/
void sub_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;
	int dif, val, val2, n = 0;

	n = list_len(stack);
	if (n < 2)
		ErrorReport_2(Err_sub_len, line_no);
	val = tmp->n;
	val2 = tmp->next->n;
	dif = val2 - val;
	tmp->next->n = dif;
	tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);

}
