#include "monty.h"

/**
 * mod_monty - function to find the reminder
 * @stack: the head of the stack
 * @line_no: the number of lines of the monty file
 *
 * Return: nothing
 **/
void mod_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;
        int rmdr, val, val2, n = 0;

        n = list_len(stack);
        if (n < 2)
                ErrorReport_2(Err_mod_len, line_no);
        val = tmp->n;
        if (val == 0)
                ErrorReport_2(Err_div_0, line_no);
        val2 = tmp->next->n;
        rmdr = val2 % val;
        tmp->next->n = rmdr;
        tmp->next->prev = tmp->prev;
        *stack = tmp->next;
        free(tmp);

}
/**
 * pchar_monty - finds the charcter of the top element of the stack
 * @stack: the head of the stack
 * @line_no: the line number of the monty file
 *
 * Return: nothing
 **/
void pchar_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;

	if (tmp->n < 0 || tmp->n > 127)
		ErrorReport_2(Err_pchar_len, line_no);
	if (tmp == NULL || stack == NULL)
		ErrorReport_2(Err_pchar_empty, line_no);
	printf("%c\n", tmp->n);
}

/**
 * pstr_monty - function to print string starting from the top of the stack
 * @stack: the head of the stack
 * @line_no: the number of lines of the monty file
 *
 * Return: nothing
 **/
void pstr_monty(stack_t **stack, unsigned int line_no)
{
	stack_t *tmp = *stack;

	(void) line_no;
	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
