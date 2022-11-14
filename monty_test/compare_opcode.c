#include "monty.h"

/**
 * comp_opc_func - for getting comparing opcode instructions
 * @s: opcodes
 * @stack: head pointer
 * @line_number: instruction line number
 * Return: nothing
 */
void comp_opc_func(char *s, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcs[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	while (opcs[i].opcode)
	{
		if (strcmp(opcs[i].opcode, s) == 0)
		{
			printf("Processing...\n");
			opcs[i].f(stack, line_number);
			printf("it works\n");
			exit(EXIT_SUCCESS);
		}
		i++;

	}
	fprintf(stderr, "L%d: unknown instruction %s", line_number, s);
	exit(EXIT_FAILURE);
}
