#include "push_swap_check.h"

int	cmdInsertEnd(t_commands *start, char *cmd)
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

void	cmdFree_List(t_commands *start)
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

void	cmdprint_list(t_commands *start)
{
	while (start->next)
	{
		printf("Cmd: %s\n", start->str);
		start = start->next;
	}
}
