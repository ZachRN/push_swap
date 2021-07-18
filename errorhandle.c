#include "includes/push_swap_check.h"

int	free_action(t_circledata *stack_a, t_commands *start, char *cmd)
{
	free(cmd);
	free_list(stack_a);
	cmdFree_List(start);
	return(-1);
}
//why did i make this though
//you're useless
