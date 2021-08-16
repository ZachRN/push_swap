#include "push_swap.h"
#include <stdio.h>

void print_list(t_circledata *stack_a)
{
	t_circledata *current;
	t_circledata *final;

	current = stack_a;
	final = current->prev;
	while (current != final)
	{
		printf("%d",current->value);
		current = current->next;
	}
	printf("%d", current->value);
}
int	main(int argc, char *argv[])
{
	int			error;
	t_head		stack_a;

	if (argc < 1)
		return (0);
	if (argc == 2)
		error = string_input_numbers(argv, &stack_a);
	else
		error = input_numbers(argc, argv, &stack_a);
	if (error == -1)
		return (0);
	error = duplication_check_two(stack_a.head);
	if (error == -1)
		return (0);
	if (error > 5)
		radix_sort(&stack_a, error);
	// else
	// 	small_sort;
	// print_list(stack_a.head);
	return (0);
}