#include "monty.h"

/**
 * ErrorReport - function to print errors on screen
 * @Error_no: the error number
 * @op_code: the operation code
 * @line_no: the line number
 *
 * Return: nothing
 **/
void ErrorReport(int Error_no, char *op_code, unsigned int line_no)
{
	switch (Error_no)
	{
		case 100:
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
			break;
		case 200:
			fprintf(stderr, "Error: Can't open file %s\n", op_code);
			exit(EXIT_FAILURE);
			break;
		case 300:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op_code);
			exit(EXIT_FAILURE);
			break;
		case 400:
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
			break;
		case 500:
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 600:
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 700:
			fprintf(stderr, "L%d: can't pop, an empty stack\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 800:
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
			exit(EXIT_FAILURE);
			break;
	}
}

/**
 * ErrorReport_2 - function to print the error
 * @Error_no: the error number
 * @line_no: the nubmer of lines of the monty file
 *
 * Return: nothing
 **/
void ErrorReport_2(int Error_no, unsigned int line_no)
{
	switch (Error_no)
	{
		case 900:
			fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 1000:
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 1100:
			fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 1200:
			fprintf(stderr, "L%d: division by zero\n", line_no);
			exit(EXIT_FAILURE);
			break;
		case 1300:
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
			exit(EXIT_FAILURE);
			break;
	}
}
