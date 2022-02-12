/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sort_value_radix.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:49:50 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:19 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_head *stack_a)
{
	t_circledata	*current;
	t_circledata	*final_node;
	int				max;

	current = stack_a->head;
	final_node = current->prev;
	max = current->value;
	while (current != final_node)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if (current->value > max)
		max = current->value;
	return (max);
}

void	min_do(t_circledata *cur, t_circledata *final, int max, int i)
{
	t_circledata	*min_node;
	t_circledata	*search;

	search = cur;
	while (search != final)
	{
		if (search->value <= max && search->radix == -1)
		{
			max = search->value;
			min_node = search;
		}
		search = search->next;
	}
	if (search->value <= max && search->radix == -1)
		min_node = search;
	min_node->radix = i;
}

void	radix_value_assign(t_head *stack_a, int amount)
{
	t_circledata	*current;
	t_circledata	*final;
	int				i;
	int				max;

	current = stack_a->head;
	final = current->prev;
	max = find_max(stack_a);
	i = 0;
	while (i < amount)
	{
		min_do(current, final, max, i);
		i++;
	}
}
