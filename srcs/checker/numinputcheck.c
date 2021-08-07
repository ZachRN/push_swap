#include "push_swap_check.h"

int	ps_atoi(char *str, int *numInput)
{
	int			sign;
	int			i;
	long int	value;

	sign = 1;
	i = 0;
	value = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i = 1;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		if (value > 2147483647 || value * -1 < -2147483648)
			return (-1);
		i++;
	}
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '\0'))
		return (-1);
	*numInput = (int)value;
	return (1);
}

int	input_numbers(int argc, char *argv[], t_head *stack_a)
{
	int	input;
	int	numInput;
	int	error;

	input = 1;
	numInput = 0;
	error = ps_atoi(argv[1], &numInput);
	if (error == -1)
		return (error_call());
	stack_a->head = firstEntry(numInput);
	while (error != -1 && input < argc - 1)
	{
		error = ps_atoi(argv[input + 1], &numInput);
		if (error == -1)
			break ;
		error = insertEnd(stack_a->head, numInput);
		input++;
	}
	if (error == -1)
	{
		free_list(stack_a->head);
		return (error_call());
	}
	return (1);
}

int	dupe_check_list(t_circledata *stack_a, int numinput, int *list)
{
	int	dupe_nav;

	dupe_nav = 0;
	while (dupe_nav < numinput)
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

int	duplication_check_two(t_circledata *stack_a, int argc)
{
	t_circledata	*final_node;
	int				numinput;
	int				*list;
	int				error;

	list = (int *)malloc(sizeof(int) * argc);
	if (!list)
		return (error_call());
	final_node = stack_a->prev;
	numinput = 1;
	list[0] = final_node->value;
	while (stack_a != final_node && error > 0)
	{
		error = dupe_check_list(stack_a, numinput, list);
		if (error == -1)
		{
			free(stack_a);
			return (error_call());
		}
		list[numinput] = stack_a->value;
		stack_a = stack_a->next;
		numinput++;
	}
	free(list);
	return (1);
}
