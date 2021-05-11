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
