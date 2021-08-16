#include "push_swap.h"

int	error_call(t_circledata *stack_a)
{
	free_list(stack_a);
	write(1, "Error\n", 6);
	return (-1);
}
