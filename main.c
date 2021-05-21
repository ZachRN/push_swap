#include <stdio.h>
#include <stdlib.h>
#include "includes/push_swap_check.h"

int main(void)
{
	char *str = "Hello I am me";
	int len;

	len = ft_strlen(str);
	printf("%d\n",len);
	return (0);
}

// int action_check(char *str)
// {
// 	static char actions[ACTION_AMT][ACTION_STRLEN_MAX] =
// 	{
// 		"sa",
// 		"sb",
// 		"ss",
// 		"pa",
// 		"pb",
// 		"ra",
// 		"rb",
// 		"rr",
// 		"rra",
// 		"rrb",
// 		"rrr"
// 	};
// 	int i;

// 	i = 0;
// 	while (i < ACTION_AMT)
// 	{
// 		if (ft_strncmp(str, actions[i], 6) == 0)
// 			return (1);
// 		i++;
// 	}
// 	return (-1);
// }

// int	main(int argc, char *argv[])
// {
// 	int	*stack_a;
// 	int input;
// 	int error;
// 	char *line;

// 	if (!(argc > 1))
// 		return (0);
// 	stack_a = (int *)malloc(sizeof(int) * argc);
// 	input = 0;
// 	error = 1;
// 	if (!stack_a)
// 	{
// 		printf("Error Only One Input\n");
// 		return (0);
// 	}
// 	while (error != -1 && input < argc - 1)
// 	{
// 		error = ps_atoi(argv[input + 1], &stack_a[input]);
// 		input++;
// 	}
// 	if (error == -1)
// 	{
// 		free(stack_a);
// 		printf("Error Invalid Number\n");
// 		return (0);
// 	}
// 	error = duplication_check(stack_a, argc);
// 	if (error == -1)
// 	{
// 		free(stack_a);
// 		printf("Error Duplicated Number\n");
// 		return (0);
// 	}
// 	input = 0;
// 	while (input < argc - 1)
// 	{
// 		printf("%d\n", stack_a[input]);
// 		input++;
// 	}
// 	get_next_line(0, &line);
// 	error = action_check(line);
// 	if (error == -1)
// 	{
// 		free(stack_a);
// 		if (line)
// 			free(line);
// 		printf("Error Invalid Action\n");
// 		return (0);
// 	}
// 	if (stack_a)
// 		free(stack_a);
// 	if (line)
// 		free(line);
// 	system("leaks a.out");
// 	return (0);
// }
