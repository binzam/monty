#include "monty.h"

/**
 * add_st - changes mode of push to stack.
 * @stack: pointer to stack.
 * @nline: line number.
 *
 * Return: no return
 */
void add_st(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
 * add_qu - changes mode of push to queue
 * @stack: pointer to stack.
 * @nline: line number.
 *
 * Return: no return
 */
void add_qu(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 1;
}
