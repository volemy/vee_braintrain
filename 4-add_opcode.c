#include "monty.h"
/**
 * add- function that adds the top two elements of stack
 * @stack: pointer to stack
 * line_number: number where the add function is called
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	stack_t *temp = (*stack)->next;
	(*stack)->next = temp->next;
	free(temp);
}
