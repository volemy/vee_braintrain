#include "monty.h"
/**
 * pop - function that remove the top element from  stack
 * @stack: pointer to  pointer to  stack
 * @line_number: current line number
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		monty_free_all();
		exit(EXIT_FAILURE);
	}

	monty_remove_stack_node();

	program->stack_len--;
}
