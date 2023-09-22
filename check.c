#include "monty.h"
#include <stdlib.h>

arg_t arg = {0, 0};

/**
 * commentCheck - checks if line is a comment.
 * @line: struct containing line content and number.
 *
 * Return: true if comment otherwise false.
 */
bool commentCheck(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * argumentCheck - checks arg validity.
 * @token: argument to be checked.
 *
 * Return: true if valid otherwise false.
 */
bool argumentCheck(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * pushCheck - check if push opcode is being used and sets
 * global argument variable if true.
 * @line: struct containg line content and number.
 * @opcode: opcode to compare.
 * @meta: struct containing all alocated memory.
 *
 * Return: NAIN.
 */
void pushCheck(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) &&  !argumentCheck(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(meta->buf);
		freeStack(&(meta->stack));
		fclose(meta->file);
		free(meta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}
