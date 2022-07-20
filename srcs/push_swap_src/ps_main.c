/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:46:32 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/20 12:16:08 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			error;
	t_head		stack_a;

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
	if (error > 5)
		radix_sort(&stack_a, error);
	else
		short_sort(&stack_a, error);
	exit(EXIT_SUCCESS);
}
