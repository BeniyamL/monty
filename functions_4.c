#include "monty.h"

/**
 * stack_monty - sets the format of the data to a stack(LIFO)
 * @stack: the head of the stack
 * @line_no: the line number of the monty file
 *
 * Return: nothing
 **/
void stack_monty(stack_t **stack, unsigned int line_no)
{
	(*stack)->n = flag_stack;
	(void) line_no;
}

/**
 * queue_monty - sets the format of the data to a stack(FIFO)
 * @stack: the head of the stack
 * @line_no: the line number of the monty file
 *
 * Return: nothing
 **/
void queue_monty(stack_t **stack, unsigned int line_no)
{
	(*stack)->n = flag_queue;
	(void) line_no;
}

