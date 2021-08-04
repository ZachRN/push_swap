#include "includes/push_swap_check.h"

int action_check(char *str)
{
	static const char actions[ACTION_AMT][ACTION_STRLEN_MAX] =
	{
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
	int i;

	i = 0;
	while (i < ACTION_AMT)
	{
		if (ft_strncmp(str, actions[i], 4) == 0)
			return (1);
		i++;
	}
	return (-1);
}

int action_input(t_circledata *stack_a, t_commands	*start;)
{
	char 		*cmd;
	int			error;

	start = (t_commands *)malloc(sizeof(t_commands));
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
			return (free_action(stack_a, start, cmd));
		cmdInsertEnd(start, cmd, error);
	}
	cmdprint_list(start);
	free(cmd);
	cmdFree_List(start);
	return(1);
}