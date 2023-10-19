#include "monty.h"
/**
 * monty_free_stack - function that frees the memory allocated for stack
 * @stack: pointer to head or bottom of stack_t
 *
 */
void monty_free_stack(stack_t *stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * monty_delete_stack_node - function that deletes the top element from stack
 *
 */
void monty_delete_stack_node(void)
{
	stack_t *tmp;

	tmp = args->head;
	args->head = tmp->next;
	free(tmp);
}
