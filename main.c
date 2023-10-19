#include "monty.h"
/**
 * main - monty interpreter function
 * @argc: number of command line arguments
 * @argv: array of strings with command line arguments
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		char *opcode = strtok(line, " \n");

		if (opcode == NULL)
		{
			continue;
		}

		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \n");

			if (arg == NULL)
			{
				dprintf(2, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			int value = atoi(arg);

			push(&stack, line_number, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			dprintf(2, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	if (line)
	{
		free(line);
	}
	fclose(file);

	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (0);
}
