/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_actions_sr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:30:52 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:30:53 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

void	rotate(t_head *stack_head)
{
	t_circledata	*rotate;

	if (stack_head->head == NULL)
		return ;
	rotate = stack_head->head;
	rotate = rotate->next;
	stack_head->head = rotate;
}

void	swap(t_head *stack_head)
{
	t_circledata	*current;
	t_circledata	*next;
	t_circledata	*prev;

	if (stack_head->head == NULL)
		return ;
	current = stack_head->head;
	if (current->next == current)
		return ;
	stack_head->head = current->next;
	next = current->next;
	prev = current->prev;
	prev->next = next;
	next->prev = prev;
	current->prev = next;
	prev = next->next;
	next->next = current;
	current->next = prev;
	prev->prev = current;
}

void	swap_both(t_head *stack_a, t_head *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate_both(t_head *stack_a, t_head *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
