/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_actioninputcheck.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:29:26 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:31:54 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

int	action_check(char *str)
{
	int					i;
	static const char	actions[ACTION_AMT][ACTION_STRLEN_MAX] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};

	i = 0;
	while (i < ACTION_AMT)
	{
		if (ft_strncmp(str, actions[i], 4) == 0)
			return (1);
		i++;
	}
	return (-1);
}

int	action_input(t_circledata *stack_a, t_commands	*start)
{
	char		*cmd;
	int			error;

	start->str = NULL;
	start->next = NULL;
	if (!start)
	{
		free(stack_a);
		return (-1);
	}
	while (get_next_line(0, &cmd) > 0)
	{
		error = action_check(cmd);
		if (error == -1)
			return (error_action(stack_a, start, cmd));
		cmdinsertend(start, cmd);
	}
	return (1);
}
