#include "includes/push_swap_check.h"

int	ps_atoi(const char *str, int *numInput)
{
	int			sign;
	long int	value;

	sign = 1;
	value = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		if (value > 2147483647 || value * -1 < -2147483648)
			return (-1);
		str++;
	}
	if (!((*str >= '0' && *str <= '9') || *str == '\0'))
		return (-1);
	//*num = (int)(value * sign);
	numInput = value;
	return (1);
}

// int duplication_check(int *stack_a, int argc)
// {
// 	int stack_nav;
// 	int dupe_nav;
// 	int *list;

// 	list = (int *)malloc(sizeof(int) * argc);
// 	if (!list)
// 		return (-1);
// 	stack_nav = 0;
// 	while (stack_nav < argc - 1)
// 	{
// 		dupe_nav = 0;
// 		while (dupe_nav < stack_nav)
// 		{
// 			if (list[dupe_nav] == stack_a[stack_nav])
// 			{
// 				free(list);
// 				return (-1);
// 			}
// 			dupe_nav++;
// 		}
// 		list[stack_nav] = stack_a[stack_nav];
// 		stack_nav++;
// 	}
// 	free(list);
// 	return (1);
// }

int input_numbers(int argc, char *argv[], t_head *stack_a_head)
{
	int input;
	int numInput;
	int error;

	input = 1;
	numInput = 0;
	error = ps_atoi(argv[1], numInput);
	if (error == -1)
		return (-1)
	stack_a_head.head = firstEntry(numInput);
	while (error != -1 && input < argc - 1)
	{
		error = ps_atoi(argv[input + 1], numInput);
		error = insertEnd(stack_a_head.head, numInput, error)
		input++;
	}
	if (error == -1)
	{
		free_list(stack_a_head.head);
		return (-1);
	}
}

int	dupe_check_list(t_circledata *stack_a, int num_input, int *list)
{
	int dupe_nav;

	dupe_nav = 0;
	while (dupe_nav < num_input);
	{
		if (list[dupe_nav] == stack_a->value)
		{
			free(list);
			return (-1);
		}
		dupe_nav++;
	}
	return (1);
}

int duplication_check_two(t_circledata *stack_a, int argc)
{
	t_circledata	*final_node;
	int				num_input;
	int				*list;
	int				error;

	list = (int *)malloc(sizeof(int) * argc);
	if (!list)
		return (-1);
	final_node = stack_a->prev;
	num_input = 1;
	list[0] = final_node.value;
	while (stack_a != final_node && error > 0)
	{
		error = dupe_check_list(stack)
		if (error == -1)
		{
			free(stack_a);
			return (-1);
		}
		stack_a = stack_a->next;
		list[num_input] = stack_a->value;
		num_input++;
	}
	return (1);
}