/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:32:06 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/20 12:16:46 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

int	main(int argc, char *argv[])
{
	int			error;
	t_head		stack_a;
	t_commands	start;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		error = string_input_numbers(argv, &stack_a);
	else
		error = input_numbers(argc, argv, &stack_a);
	if (error == -1)
		exit(EXIT_FAILURE);
	error = duplication_check_two(stack_a.head);
	if (error == -1)
		exit(EXIT_FAILURE);
	error = action_input(stack_a.head, &start);
	if (error == -1)
		exit(EXIT_FAILURE);
	error = sort_list(&stack_a, &start);
	exit(EXIT_SUCCESS);
}
