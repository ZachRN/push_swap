#include <stdio.h>
#include <stdlib.h>
#include "push_swap_check.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((a[i] == b[i]) && (a[i] != '\0' && b[i] != '\0') && (i < len))
	{
		i++;
	}
	if (i < len)
		return (a[i] - b[i]);
	return (0);
}

int action_check(char *str)
{
	static char actions[ACTION_AMT][ACTION_STRLEN_MAX] =
	{
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};
	int i;

	i = 0;
	while (i < ACTION_AMT)
	{
		if (ft_strncmp(str, actions[i], 6) == 0)
			return (1);
		i++;
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int input;
	int error;
	char *line;

	if (!(argc > 1))
		return (0);
	stack_a = (int *)malloc(sizeof(int) * argc);
	input = 0;
	error = 1;
	if (!stack_a)
	{
		printf("Error Only One Input\n");
		return (0);
	}
	while (error != -1 && input < argc - 1)
	{
		error = ps_atoi(argv[input + 1], &stack_a[input]);
		input++;
	}
	if (error == -1)
	{
		free(stack_a);
		printf("Error Invalid Number\n");
		return (0);
	}
	error = duplication_check(stack_a, argc);
	if (error == -1)
	{
		free(stack_a);
		printf("Error Duplicated Number\n");
		return (0);
	}
	input = 0;
	while (input < argc - 1)
	{
		printf("%d\n", stack_a[input]);
		input++;
	}
	get_next_line(0, &line);
	error = action_check(line);
	if (error == -1)
	{
		free(stack_a);
		if (line)
			free(line);
		printf("Error Invalid Action\n");
		return (0);
	}
	if (stack_a)
		free(stack_a);
	if (line)
		free(line);
	system("leaks a.out");
	return (0);
}
