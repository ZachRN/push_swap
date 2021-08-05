#include "push_swap_check.h"

int	error_action(t_circledata *stack_a, t_commands *start, char *cmd)
{
	free(cmd);
	free_list(stack_a);
	start = start->next;
	cmdFree_List(start);
	write(1, "Error\n", 6);
	return (-1);
}

int	error_call(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	OK_call(t_head *stack_a, t_commands *start)
{
	free_list(stack_a->head);
	start = start->next;
	cmdFree_List(start);
	write(1, "OK\n", 3);
	return (1);
}

int	KO_call(t_head *stack_a, t_head *stack_b, t_commands *start)
{
	write(1,"4",1);
	free_list(stack_a->head);
	free_list(stack_b->head);
	start = start->next;
	cmdFree_List(start);
	write(1, "KO\n", 2);
	return (-1);
}
