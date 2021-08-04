#include "./push_swap_check.h"

void push(t_head *stack_one_head, t_head *stack_two_head)
{
	t_circledata *next;
	t_circledata *current;
	t_circledata *prev;

	if (stack_b_head->head == NULL)
		return;
	current = stack_b_head->head;
	next = current->next;
	if (current == next)
		stack_b_head = NULL;
	else
		stack_b_head->head = next;
	prev = current->prev;
	prev->next = next;
	next->prev = prev;
	next = stack_a_head->head;
	prev = next->prev;
	prev->next = current;
	next->prev = current;
	stack_a_head->head = current;
}

void push_ab()