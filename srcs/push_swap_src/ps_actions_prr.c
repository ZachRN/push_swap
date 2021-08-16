#include "push_swap.h"

void	reverse_rotate(t_head *stack_head)
{
	t_circledata	*prev;

	if (stack_head->head == NULL)
		return ;
	prev = stack_head->head;
	prev = prev->prev;
	stack_head->head = prev;
}

void	reverse_rotate_both(t_head *stack_a, t_head *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

void	push(t_head *stack_take_head, t_head *stack_give_head)
{
	t_circledata	*next;
	t_circledata	*current;
	t_circledata	*prev;

	if (stack_give_head->head == NULL)
		return ;
	current = stack_give_head->head;
	next = current->next;
	if (current == next)
		stack_give_head->head = NULL;
	else
		stack_give_head->head = next;
	prev = current->prev;
	prev->next = next;
	next->prev = prev;
	if (stack_take_head->head == NULL)
		return (push_empty(stack_take_head, current));
	next = stack_take_head->head;
	prev = next->prev;
	prev->next = current;
	next->prev = current;
	current->next = next;
	current->prev = prev;
	stack_take_head->head = current;
}

void	push_empty(t_head *stack_take_head, t_circledata *current)
{
	current->next = current;
	current->prev = current;
	stack_take_head->head = current;
}
