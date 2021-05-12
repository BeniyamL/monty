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
