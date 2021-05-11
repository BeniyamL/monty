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
	}
}
