#include "monty.h"

/**
 * pall - function that prints all elements of stack
 * @stack: pointer to pointer to stack
 * @line_num:
 *
 * Return: Nothing(success)
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return;
	}
	UNUSED(line_num);

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
