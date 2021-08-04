#include "./push_swap_check.h"

void	swap(t_head *stack_head)
{
	t_circledata *first;
	t_circledata *second;

	if (stack_a_head->head == NULL)
		return;
	first = stack_a_head->head;
	if (first->next == first)
		return;
	second = first->next;
	second->prev = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	stack_a_head->head = second;
}

void	swap_ab(t_head *stack_a_head, t_head *stack_b_head)
{
	swap(stack_a_head);
	swap(stack_b_head);
}