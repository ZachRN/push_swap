/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:46:32 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:46:32 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else
		short_sort(&stack_a, error);
	return (0);
}
