#include "push_swap.h"

int	error_call(t_circledata *stack_a)
{
	free_list(stack_a);
	write(1, "Error\n", 6);
	return (-1);
}

void	free_all(t_head *stack_a, t_head *stack_b)
{
	if (stack_a->head != NULL)
		free_list(stack_a->head);
	if (stack_b->head != NULL)
		free_list(stack_b->head);
}
