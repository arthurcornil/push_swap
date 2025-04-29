/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:51:46 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 12:57:47 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_number(char *str)
{
	if (*str == 0)
		return (false);
	if (*str == '+' || *str == '-')
		str ++;
	if (*str == 0)
		return (false);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str ++;
	}
	return (true);
}

static long int	ft_atol(const char *str)
{
	bool			is_negative;
	long int		result;

	is_negative = false;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = true;
		str ++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		if (is_negative)
			result -= *str - '0';
		else
			result += *str - '0';
		str ++;
	}
	return (result);
}

bool	contains_duplicates(int size, int *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j])
				return (true);
			j ++;
		}
		i ++;
	}
	return (false);
}

void	exit_elegantly(t_stack *stack_a, t_stack *stack_b, t_error error)
{
	if (stack_a->values)
		free(stack_a->values);
	if (stack_b->values)
		free(stack_b->values);
	if (error == WRONG_INPUT_FORMAT)
		ft_putstr_fd(2, "Error\n");
	else if (error != NONE)
		exit(1);
	exit(0);
}

void	parse_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	long int	curr_val;

	stack_a->values = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack_a->values)
		exit_elegantly(stack_a, stack_b, DYNAMIC_ALLOCATION_FAILURE);
	stack_b->values = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack_b->values)
		exit_elegantly(stack_a, stack_b, DYNAMIC_ALLOCATION_FAILURE);
	i = 0;
	while (i < argc - 1)
	{
		if (!is_number(argv[i + 1]))
			exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
		curr_val = ft_atol(argv[i + 1]);
		if (curr_val > 2147483647 || curr_val < -2147483648)
			exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
		stack_a->values[i] = (int) curr_val;
		i ++;
	}
	if (contains_duplicates(argc - 1, stack_a->values))
		exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
	stack_a->len = argc - 1;
	stack_b->len = 0;
}
