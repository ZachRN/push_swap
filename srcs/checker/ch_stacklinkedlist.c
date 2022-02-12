/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_stacklinkedlist.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:33:28 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:33:46 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

t_circledata	*firstentry(int value)
{
	t_circledata	*temp;

	temp = (t_circledata *)malloc(sizeof(t_circledata));
	if (!temp)
		return (NULL);
	temp->value = value;
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
	start->prev = new_node;
	new_node->prev = final_node;
	final_node->next = new_node;
	return (1);
}

void	free_list(t_circledata *start)
{
	t_circledata	*final_node;
	t_circledata	*nav;

	if (start == NULL)
		return ;
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
