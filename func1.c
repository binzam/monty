#include "monty.h"

/**
 * push - pushes node to top of stack.
 * @stack: pointer to head node pointer of stack
 * @nline: line number.
 *
 * Return: no return
 */
void push(stack_t **stack, unsigned int nline)
{
	stack_t *temp;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	temp->next = *stack;
	temp->prev = NULL;
	temp->n = arg.arg;
	if (*stack)
		(*stack)->prev = temp;
	*stack = temp;
}

/**
 * pall - prints data of all nodes in stack.
 * @stack: pointer to head node pointer of stack.
 * @nline: line number.
 *
 * Return: no return
 */
void pall(stack_t **stack, unsigned int nline)
{
	stack_t *temp;
	(void)nline;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * freeStack - frees all nodes in a stack.
 * @stack: pointer to head node pointer of a stack.
 *
 * Return: no return
 */
void freeStack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * nop - does no return.
 * @stack: pointer to head node pointer of stack.
 * @nline: line number.
 *
 * Return: no return
 */
void nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * is_alpha - checks if int is an alphabet.
 * @c: int
 *
 * Return: 1 (true), 0 otherwise.
 */
int is_alpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}
