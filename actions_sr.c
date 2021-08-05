#include "push_swap_check.h"

void	rotate(t_head *stack_head)
{
	t_circledata	*rotate;

	if (stack_head->head == NULL)
		return ;
	rotate = stack_head->head;
	rotate = rotate->next;
	stack_head->head = rotate;
}

void	swap(t_head *stack_head)
{
	t_circledata	*current;
	int				numone;
	int				numtwo;

	if (stack_head->head == NULL)
		return ;
	current = stack_head->head;
	if (current->next == current)
		return ;
	numone = current->value;
	current = current->next;
	numtwo = current->value;
	current->value = numone;
	current = current->prev;
	current->value = numtwo;
}

void	swap_both(t_head *stack_a, t_head *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate_both(t_head *stack_a, t_head *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
