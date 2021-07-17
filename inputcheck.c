#include "includes/push_swap_check.h"

int	ps_atoi(const char *str, int *num)
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
	*num = (int)(value * sign);
	return (1);
}

int duplication_check(int *stack_a, int argc)
{
	int stack_nav;
	int dupe_nav;
	int *list;

	list = (int *)malloc(sizeof(int) * argc);
	if (!list)
		return (-1);
	stack_nav = 0;
	while (stack_nav < argc - 1)
	{
		dupe_nav = 0;
		while (dupe_nav < stack_nav)
		{
			if (list[dupe_nav] == stack_a[stack_nav])
			{
				free(list);
				return (-1);
			}
			dupe_nav++;
		}
		list[stack_nav] = stack_a[stack_nav];
		stack_nav++;
	}
	free(list);
	return (1);
}