#include "./push_swap_check.h"

int action_call(t_head *stack_a_head, t_head *stack_b_head, t_commands *start)
{
	if (start->str == "sa")
		swap_a();
	else if (start->str == "sb")
		swap_b();
	else if (start->str == "ss")
		swap_ab();
	else if (start->str == "pa")
		push_a();
	else if (start->str == "pb")
		push_b();
	else if (start->str == "ra")
		rotate_a()
	else if (start->str == "rb")
		rotate_b()
	else if (start->str == "rr")
		rotate_ab()
	else if (start->str == "rra")
		reverse_rotate_a()
	else if (start->str == "rrb")
		reverse_rotate_b()
	else if (start->str == "rrr")
		reverse_rotate_ab()
	
}

int sort_list(t_head *stack_a_head, t_commands *start)
{
	t_head *stack_b_head;

}