#include "monty.h"
/**
 * pint - function that prints value at top of stack
 * @stack:pointer to pointer to stack
 * @line_num: current line
 *
 * Return: nothing(success)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
