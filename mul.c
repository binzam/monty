#include "monty.h"
#include <stdlib.h>

/**
 * mulop - multiplies top 2 elements ans stores res in 2nd element.
 * @stack: pointer to the head node pointer of stack
 * @nline: line number
 *
 * Return: no return
 */
void mulop(stack_t **stack, unsigned int nline)
{
stack_t *temp;

if (!(*stack) || !(*stack)->next)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", nline);
exit(EXIT_FAILURE);
}

temp = *stack;
(*stack)->next->n *= (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}
