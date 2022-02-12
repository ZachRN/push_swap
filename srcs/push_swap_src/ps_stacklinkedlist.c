/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stacklinkedlist.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:50:05 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:50:13 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_circledata	*firstentry(int value)
{
	t_circledata	*temp;

	temp = (t_circledata *)malloc(sizeof(t_circledata));
	if (!temp)
		return (NULL);
	temp->value = value;
	temp->radix = -1;
	temp->prev = temp;
	temp->next = temp;
	return (temp);
}

int	insertend(t_circledata *start, int value)
{
	t_circledata	*final_node;
	t_circledata	*new_node;

	new_node = (t_circledata *)malloc(sizeof(t_circledata));
	if (!new_node)
		return (-1);
	final_node = start->prev;
	new_node->value = value;
	new_node->next = start;
	new_node->radix = -1;
	start->prev = new_node;
	new_node->prev = final_node;
	final_node->next = new_node;
	return (1);
}

void	free_list(t_circledata *start)
{
	t_circledata	*final_node;
	t_circledata	*nav;

	final_node = start->prev;
	nav = start;
	while (start != final_node)
	{
		start = start->next;
		free(nav);
		nav = start;
	}
	free(nav);
}

int	stack_check(t_head *stack_a)
{
	t_circledata	*current;
	int				testvalue;

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
