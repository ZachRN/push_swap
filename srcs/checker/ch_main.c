/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:32:06 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:32:07 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

int	main(int argc, char *argv[])
{
	int			error;
	t_head		stack_a;
	t_commands	start;

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
	error = action_input(stack_a.head, &start);
	if (error == -1)
		return (0);
	error = sort_list(&stack_a, &start);
	return (0);
}
