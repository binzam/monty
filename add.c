#include "monty.h"
#include <stdlib.h>

/**
 * addop - finds sum of top two elements
 * @stack: pointer to the head node pointer of stack
 * @nline: line number
 *
 * Return: no return
 */
void addop(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't add, stack too short\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
(*stack)->next->n += (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}
