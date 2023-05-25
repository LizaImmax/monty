#include "monty.h"

/**
 * pall - prints the stack
 * @stack: stack given by main
 * @line_num: ammount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	print_stack(*stack);
}
