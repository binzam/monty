#include "monty.h"
#include <stdlib.h>

/**
 * get_op_func - searches and matches text to opcode
 * then returns corresponding function.
 * @line: struct containing line content and number.
 * @meta: struct containing all allocated memory.
 *
 * Return: pointer to relevant function.
 */
void (*get_op_func(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", addop},
	{"sub", subop},
	{"mul", mulop},
	{"div", divop},
	{"mod", modop},
	{"nop", nop},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotlop},
	{"rotr", rotrop},
	{"stack", add_st},
	{"queue", add_qu},
	{NULL, NULL}};

	if (commentCheck(line))
		return (nop);

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			pushCheck(line, meta, ops[i].opcode);
			if (arg.flag == 1 && strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (q_push);
			}
			free(line.content);
			return (ops[i].f);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n",
			line.number, line.content[0]);
	free(line.content);
	free(meta->buf);
	freeStack(&(meta->stack));
	fclose(meta->file);
	free(meta);
	exit(EXIT_FAILURE);
}
