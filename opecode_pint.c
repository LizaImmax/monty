#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * opcode_pint - prints int value at top of list; failure if list is empty
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		printf("%i\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * opcode_pop - removes top element of stack, if list > 1 elements, second element
 * becomes top of stack; failure if list is empty
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack)
	{
		if ((*stack)->next)
		{
			*stack = (*stack)->next;
			(*stack)->prev = NULL;
			free(temp);
		}
		else
		{
			free(*stack);
			*stack = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}
}
