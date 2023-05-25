#include "monty.h"

/**
 * opcode_push - push element to top of stack and bottom if queue;
 * failure if second token from iterpreter is not an int value
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */

void opcode_push(stack_t **stack, unsigned int line_number)
{
	char *push_n = NULL;
	int value = 0;
	stack_t *new = NULL, *temp = *stack;

	push_n = strtok(NULL, " ");
	atoi_filter(push_n, stack, line_number);
	value = atoi(push_n);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup(stack);
		exit(EXIT_FAILURE);
	}

	new->n = value;
	if (is_queue)
	{
		if (*stack)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*stack = new;
		new->prev = temp;
		new->next = NULL;
	}
	else
	{
		if (*stack)
			(*stack)->prev = new;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}

/**
 * atoi_filter - checksif string represents a valid integer.
 * @str: string to be checked for compatibility with atoi
 * @stack: first element of a doubly linked list of integers
 * @line_number: line of monty text file currently seen by interpreter
 */
void atoi_filter(char *str, stack_t **stack, unsigned int line_number)
{
	int i;

	if (!str || str[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		cleanup(stack);
		exit(EXIT_FAILURE);
	}

	for (i = 0; str[i]; i++)
	{
		if (i == 0)
		{
			if (str[i] != '-' &&
			    !(str[i] >= 0 + '0' && str[i] <= 9 + '0'))
			{
				fprintf(stderr, "L%u: usage: push integer\n",
					line_number);
				cleanup(stack);
				exit(EXIT_FAILURE);
			}
		}
		else if (!(str[i] >= 0 + '0' && str[i] <= 9 + '0'))
		{
			fprintf(stderr, "L%u: usage: push integer\n",
				line_number);
			cleanup(stack);
			exit(EXIT_FAILURE);
		}
	}
}
