#include <stdio.h>
#include <stdlib.h>
#include "push_swap_check.h"

int	main(int argc, char *argv[])
{
	int			error;
	t_head		stack_a;
	t_commands	start;

	if (!(argc > 1))
	{
		printf("error");
		return (0);
	}
	error = input_numbers(argc, argv, &stack_a);
	if (error == -1)
		return (0);
	error = duplication_check_two(stack_a.head, argc);
	if (error == -1)
		return (0);
	error = action_input(stack_a.head, &start);
	if (error == -1)
		return (0);
	error = sort_list(&stack_a, &start);
	return (0);
}
