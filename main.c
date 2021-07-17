#include <stdio.h>
#include <stdlib.h>
#include "includes/push_swap_check.h"

int	main(int argc, char *argv[])
{
	int error;
	t_head stack_a_head;

	if (!(argc > 1))
		return (0);
	error = input_numbers(argc, argv, stack_a_head);
	if (error == -1)
		return (0);
	error = duplication_check(stack_a, argc);
	if (error -1)
		return (0);
	error = action_input(stack_a);
	if (error -1)
		return (0);
	system("leaks a.out");
	return (0);
}
	//char *line;
	//int	*stack_a;
	//int input;
	//stack_a = (int *)malloc(sizeof(int) * argc);
	// input = 1;
	// error = 1;
	// if (argc - 1 < 1)
	// {
	// 	printf("Error Only One Input\n");
	// 	return (0);
	// }
	// error = ps_atoi(argv[1]);
	// while (error != -1 && input < argc - 1)
	// {
	// 	error = ps_atoi(argv[input + 1]);
	// 	input++;
	// }
	// ErrorCheck(error, stack_a_head.head)
	// error = duplication_check(stack_a, argc);
	// if (error == -1)
	// {
	// 	free(stack_a);
	// 	printf("Error Duplicated Number\n");
	// 	return (0);
	// }
	// print_list()
	// get_next_line(0, &line);
	// error = action_check(line);
	// if (error == -1)
	// {
	// 	free(stack_a);
	// 	if (line)
	// 		free(line);
	// 	printf("Error Invalid Action\n");
	// 	return (0);
	// }
	// if (stack_a)
	// 	free(stack_a);
	// if (line)
	// 	free(line);