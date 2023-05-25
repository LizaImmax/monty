#include "monty.h"

/**
 * opcode_rotr - rotates top element of list to bottom of list, 2nd becomes top
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *temp;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tail = *stack;
		*stack = (*stack)->next;
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = tail;
		tail->prev = temp;
		tail->next = NULL;
	}
}

/**
 * opcode_rotl - rotates bottom element of list to top of list
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */

void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->prev->next = NULL;
		(*stack)->prev = temp;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
