#include "includes/push_swap_check.h"

int action_check(char *str)
{
	static char actions[ACTION_AMT][ACTION_STRLEN_MAX] =
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
		if (ft_strncmp(str, actions[i], 6) == 0)
			return (1);
		i++;
	}
	return (-1);
}

int action_input(t_circledata *stack_a)
{
	//LINKED LIST COMMANDS TOGETHER MAKES MOST SENSE
	
}