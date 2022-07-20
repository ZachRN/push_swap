/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_short_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:48:17 by znajda        #+#    #+#                 */
/*   Updated: 2022/07/20 12:17:21 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_head *stack_a, int start)
{
	t_circledata	*data;
	t_circledata	*next;

	data = stack_a->head;
	next = data->next;
	if (data->radix == (0 + start))
		write(STDOUT_FILENO, "sa\nra\n", 6);
	else if (data->radix == (1 + start))
	{
		if (next->radix == (2 + start))
			write(STDOUT_FILENO, "rra\n", 4);
		else
			write(STDOUT_FILENO, "sa\n", 3);
	}
	else
	{
		if (next->radix == (0 + start))
			write(STDOUT_FILENO, "ra\n", 3);
		else
			write(STDOUT_FILENO, "sa\nrra\n", 7);
	}
}

void	four_sort(t_head *stack_a, t_head *stack_b, int start)
{
	t_circledata	*search;

	search = stack_a->head;
	if (search->prev->radix == (0 + start))
	{
		reverse_rotate(stack_a);
		write(STDOUT_FILENO, "rra\n", 4);
		search = search->prev;
	}
	else
	{
		while (search->radix != (0 + start))
		{
			write(STDOUT_FILENO, "ra\n", 3);
			rotate(stack_a);
			search = search->next;
		}
	}
	if (stack_check(stack_a) == 1)
		return ;
	push(stack_b, stack_a);
	write(STDOUT_FILENO, "pb\n", 3);
	three_sort(stack_a, (1 + start));
	write(STDOUT_FILENO, "pa\n", 3);
}

void	fs_efficient(t_head *stack_a, int i)
{
	if (i > 2)
	{
		while (i < 5)
		{
			reverse_rotate(stack_a);
			write(STDOUT_FILENO, "rra\n", 4);
			i++;
		}
	}
	else
	{
		while (i != 0)
		{
			rotate(stack_a);
			write(STDOUT_FILENO, "ra\n", 3);
			i--;
		}
	}
}

void	five_sort(t_head *stack_a, t_head *stack_b)
{
	t_circledata	*search;
	int				i;

	i = 0;
	search = stack_a->head;
	while (search->radix != 0)
	{
		i++;
		search = search->next;
	}
	fs_efficient(stack_a, i);
	if (stack_check(stack_a) == 1)
		return ;
	push(stack_b, stack_a);
	write(STDOUT_FILENO, "pb\n", 3);
	four_sort(stack_a, stack_b, 1);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	short_sort(t_head *stack_a, int amount)
{
	t_head	stack_b;
	int		maxbits;

	maxbits = 1;
	stack_b.head = NULL;
	if (list_check(stack_a, &stack_b) == 1)
		return ((void)(free_all(stack_a, &stack_b)));
	radix_value_assign(stack_a, amount);
	if (amount == 2)
		swap(stack_a);
	else if (amount == 3)
		three_sort(stack_a, 0);
	else if (amount == 4)
		four_sort(stack_a, &stack_b, 0);
	else if (amount == 5)
		five_sort(stack_a, &stack_b);
	free_all(stack_a, &stack_b);
}
