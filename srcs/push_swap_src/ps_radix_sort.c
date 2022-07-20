/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_radix_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:47:55 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/20 12:17:10 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_check(t_head *stack_a, t_head *stack_b)
{
	t_circledata	*current;
	int				testvalue;

	if (stack_b->head != NULL)
		return (-1);
	current = stack_a->head;
	testvalue = current->value;
	current = current->next;
	while (current != stack_a->head)
	{
		if (testvalue > current->value)
			return (-1);
		testvalue = current->value;
		current = current->next;
	}
	return (1);
}

void	bit_shift(t_head *stack_a, t_head *stack_b, int i, int num)
{
	if (((num >> i) & 1) == 1)
	{
		write(STDOUT_FILENO, "ra\n", 3);
		rotate(stack_a);
	}
	else
	{
		write(STDOUT_FILENO, "pb\n", 3);
		push(stack_b, stack_a);
	}
}

void	rs_list(t_head *stack_a, t_head *stack_b, int maxbits, int amt)
{
	t_circledata	*top_of_a;
	int				i;
	int				j;
	int				num;

	i = 0;
	while (i < maxbits)
	{
		j = 0;
		while (j < amt)
		{
			top_of_a = stack_a->head;
			num = top_of_a->radix;
			bit_shift(stack_a, stack_b, i, num);
			j++;
		}
		while (stack_b->head != NULL)
		{
			write(1, "pa\n", 3);
			push(stack_a, stack_b);
		}
		i++;
	}
}

void	radix_sort(t_head *stack_a, int amount)
{
	t_head	stack_b;
	int		maxbits;

	maxbits = 1;
	stack_b.head = NULL;
	if (list_check(stack_a, &stack_b) == 1)
		return ((void)(free_all(stack_a, &stack_b)));
	radix_value_assign(stack_a, amount);
	while (((amount - 1) >> maxbits) != 0)
		maxbits++;
	rs_list(stack_a, &stack_b, maxbits, amount);
	free_all(stack_a, &stack_b);
}
