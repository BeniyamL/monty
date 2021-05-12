#ifndef monty_h
#define monty_h

#define STACK 0
#define QUEUE 1
#define Err_user 100
#define Err_file 200
#define DELIM " \n\t"
#define Err_sys 300
#define Err_malloc 400
#define Err_user2 500
#define Err_empty 600
#define Err_empty_pop 700
#define Err_swap_len 800
#define Err_add_len 900
#define Err_sub_len 1000
#define Err_div_len 1100
#define Err_div_0 1200
#define Err_mul_len 1300
#define Err_mod_len 1400
#define Err_pchar_len 1500
#define Err_pchar_empty 1600

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


extern char *op_arg;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/** Errors.c **/
void ErrorReport(int Error_no, char *op_code, unsigned int line_no);
void ErrorReport_2(int Error_no, unsigned int line_no);

/** main.c **/
int Execute(char *op_code, stack_t **stack, unsigned int line_no);
int handle_functions(char *op_code, stack_t **stack, unsigned int line_no);

/** functions.c **/
void push_monty(stack_t **stack, unsigned int line_no);
void pall_monty(stack_t **stack, unsigned int line_no);
void pint_monty(stack_t **stack, unsigned int line_no);
void pop_monty(stack_t **stack, unsigned int line_no);
void swap_monty(stack_t **stack, unsigned int line_no);

/** free_mem.c **/
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int stack_or_queue(stack_t *stack);

/** func_helper.c **/
int is_digit(void);
int list_len(stack_t **stack);

/** functions_2.c **/
void add_monty(stack_t **stack, unsigned int line_no);
void nop_monty(stack_t **stack, unsigned int line_no);
void sub_monty(stack_t **stack, unsigned int line_no);
void div_monty(stack_t **stack, unsigned int line_no);
void mul_monty(stack_t **stack, unsigned int line_no);

/** functions_3.c **/
void mod_monty(stack_t **stack, unsigned int line_no);
void pchar_monty(stack_t **stack, unsigned int line_no);
void pstr_monty(stack_t **stack, unsigned int line_no);
#endif
