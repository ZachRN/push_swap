#include "push_swap_check.h"
#include <stdio.h>

void	action_call(t_head *stack_a, t_head *stack_b, char *action)
{
	if (ft_strncmp(action, "sa", 4) == 0)
		swap(stack_a);
	else if (ft_strncmp(action, "sb", 4) == 0)
		swap(stack_b);
	else if (ft_strncmp(action, "ss", 4) == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strncmp(action, "pa", 4) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(action, "pb", 4) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(action, "ra", 4) == 0)
		rotate(stack_a);
	else if (ft_strncmp(action, "rb", 4) == 0)
		rotate(stack_b);
	else if (ft_strncmp(action, "rr", 4) == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strncmp(action, "rra", 4) == 0)
		reverse_rotate(stack_a);
	else if (ft_strncmp(action, "rrb", 4) == 0)
		reverse_rotate(stack_b);
	else if (ft_strncmp(action, "rrr", 4) == 0)
		reverse_rotate_both(stack_a, stack_b);
}

int	list_check(t_head *stack_a, t_head *stack_b)
{
	t_circledata	*current;
	int				testvalue;

	if (stack_b->head != NULL)
		return (-1);
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

int	sort_list(t_head *stack_a, t_commands *start)
{
	t_head		stack_b;
	t_commands	*start_nav;
	int			error;

	stack_b.head = NULL;
	start_nav = start;
	while (start_nav->next)
	{
		action_call(stack_a, &stack_b, start_nav->str);
		start_nav = start_nav->next;
	}
	error = list_check(stack_a, &stack_b);
	print_list(stack_a->head);
	if (error == -1)
		return (KO_call(stack_a, &stack_b, start));
	return (OK_call(stack_a, start));
}
