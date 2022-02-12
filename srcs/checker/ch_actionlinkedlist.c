/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_actionlinkedlist.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:29:49 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:56:59 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

int	cmdinsertend(t_commands *start, char *cmd)
{
	t_commands	*new_node;

	new_node = (t_commands *)malloc(sizeof(t_commands));
	if (!new_node)
		return (-1);
	new_node->str = NULL;
	new_node->next = NULL;
	while (start->next)
		start = start->next;
	start->str = cmd;
	start->next = new_node;
	return (1);
}

void	cmdfree_list(t_commands *start)
{
	t_commands	*nav;

	if (!start)
		return ;
	nav = start;
	while (start->next != NULL)
	{
		start = start->next;
		free(nav->str);
		free(nav);
		nav = start;
	}
	free(nav);
}
