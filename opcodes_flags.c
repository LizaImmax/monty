#include "monty.h"

/**
 * opcode_stack - sets flag to treat linked list as LIFO stack
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	is_queue = 0;
}

/**
 * opcode_queue - sets flag to treat linked list as FIFO queue
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	is_queue = 1;
}
