/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ch_strnuminputcheck.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/12 13:33:50 by znajda        #+#    #+#                 */
/*   Updated: 2022/02/12 13:34:33 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_check.h"

int	str_ps_atoi(char *str, int *numInput, int i)
{
	int			sign;
	long int	value;

	sign = 1;
	value = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
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
	if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '\0'))
		return (-1);
	*numInput = (int)value * sign;
	return (i);
}

int	str_in_loop(char *str, int i, t_head *stack_a)
{
	int	error;
	int	numinput;

	numinput = 0;
	while (str[i])
	{
		i++;
		if ((ft_isdigit(str[i])) || str[i] == '-')
		{
			error = str_ps_atoi(str, &numinput, i);
			if (error == -1)
				return (error);
			i = error;
			error = insertend(stack_a->head, numinput);
		}	
	}
	return (1);
}

int	string_input_numbers(char *argv[], t_head *stack_a)
{
	int		i;
	int		numinput;
	int		error;
	char	*str;

	str = argv[1];
	numinput = 0;
	error = str_ps_atoi(str, &numinput, 0);
	i = error;
	if (error == -1)
		return (error_call(stack_a->head));
	stack_a->head = firstentry(numinput);
	error = str_in_loop(str, i, stack_a);
	if (error == -1)
		return (error_call(stack_a->head));
	return (1);
}
