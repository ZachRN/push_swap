#include "includes/push_swap_check.h"

t_circledata    *firstEntry(int value)
{
    t_circledata *temp;

    temp = (t_circledata *)malloc(sizeof(t_circledata));
    if (!temp)
        return (NULL);
    temp->value = value;
    temp->prev = temp;
    temp->next = temp;
    return (temp);
}

int     insertEnd(t_circledata *start, int value, int error)
{
    t_circledata *final_node;
    t_circledata *new_node;

    new_node = (t_circledata *)malloc(sizeof(t_circledata));
    if (!new_node)
    {
        //free_func;
        return (-1);
    }
    final_node = start->prev;
    new_node->value = value;
    new_node->next = start;
    start->prev = new_node;
    new_node->prev = final_node;
    final_node->next = new_node;
    return (error);
}
int cmdInsertEnd(t_commands *start, char *cmd, int error)
{
	t_commands *new_node;

	new_node = (t_commands *)malloc(sizeof(t_commands));
	if (!new_node)
		return (-1);
	new_node->str = NULL;
	new_node->pos = -1;
	new_node->next = NULL;
	while (start->next)
		start = start->next;
	start->str = cmd;
	start->pos = error;
	start->next = new_node;
	return (1);
}
void	cmdFree_List(t_commands *start)
{
	t_commands *nav;

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
void    free_list(t_circledata *start)
{
    t_circledata *final_node;
    t_circledata *nav;
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
void	cmdprint_list(t_commands *start)
{
	while (start->next)
	{
		printf("Cmd: %s\n", start->str);
		start = start->next;
	}
}
void    print_list(t_circledata *start)
{
    t_circledata *final_node;
    t_circledata *nav;

    final_node = start->prev;
    nav = start;
    while (nav != final_node)
    {
        printf("Value: %d\n", nav->value);
        nav = nav->next;
    }
    printf("Value: %d\n", nav->value);
}
