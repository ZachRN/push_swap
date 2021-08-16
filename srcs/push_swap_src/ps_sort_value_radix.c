#include "push_swap.h"

int		find_max(t_head *stack_a)
{
	t_circledata	*current;
	t_circledata	*final_node;
	int 			max;

	current = stack_a->head;
	final_node = current->prev;
	max = current->value;
	while (current != final_node)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if (current->value > max)
		max = current->value;
	return (max);
}

void	min_do(t_circledata *cur, t_circledata *final, int max, int i)
{
	t_circledata *min_node;

	while (cur != final)
	{
		if (cur->value < max && cur->radix == -1)
		{
			max = cur->value;
			min_node = cur;
		}
		cur = cur->next;
	}
	if (cur->value < max && cur->radix == -1)
	{
		max = cur->value;
		min_node = cur;
	}
	min_node->radix = i;
}

void	radix_value_assign(t_head *stack_a, int amount)
{
	t_circledata *current;
	t_circledata *final;
	int i;
	int max;

	current = stack_a->head;
	final = current->prev;
	max = find_max(stack_a);
	i = 0;
	while (i < amount)
	{
		min_do(current, final, max, i);
		i++;
	}
}