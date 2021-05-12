#include "monty.h"
char *op_arg = NULL;
/**
 * main - enty point for execution
 * @argc: the number of argument
 * @argv: array of argument
 *
 * Return: always success
 **/
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	size_t line_size = 0;
	char *line = NULL;
	unsigned int line_no = 1;
	int status = 0;
	char *op_code = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
		ErrorReport(Err_user, NULL, 0);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
		ErrorReport(Err_file, argv[1], 0);
	while (getline(&line, &line_size, fd) != -1)
	{
		op_code = strtok(line, DELIM);
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				continue;
				line_no++;
			}
			op_arg = strtok(NULL, DELIM);
			status = Execute(op_code, &stack, line_no);
			if (status == Err_sys)
			{
				ErrorReport(Err_sys, op_code, line_no);
				free_stack(&stack);
				fclose(fd);
			}
		}
		line_no++;
	}
	free_stack(&stack);
	free(line);
	fclose(fd);
	return (0);
}

/**
 * Execute - function to execute the operation code
 * @stack: the given code
 * @line_no: the given argument
 * @op_code: the operation code
 *
 * Return: the status of the execution
 **/
int Execute(char *op_code, stack_t **stack, unsigned int line_no)
{
	int handler = 0;

	handler = handle_functions(op_code, stack, line_no);
	if (handler == 0)
	{
		return (Err_sys);
	}
	return (0);
}

/**
 * handle_functions - function to handle operation
 * @stack: the operation
 * @line_no: the line number of the monty file
 * @op_code: the operation code
 *
 * Return: the corresponding function handle or null if it fails
 **/
int handle_functions(char *op_code, stack_t **stack, unsigned int line_no)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{NULL, NULL}
	};

	while (instruction[i].opcode)
	{
		if (strcmp(op_code, instruction[i].opcode) == 0)
		{
			instruction[i].f(stack, line_no);
			return (1);
		}
		i++;
	}
	return (0);
}
