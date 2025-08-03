/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:36:42 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:42:28 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

bool	contains_duplicates(int size, int *values)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (true);
			j ++;
		}
		i ++;
	}
	return (false);
}

void	handle_errors(unsigned int num_elems, char **elems,
		t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	i;
	long int		curr_val;

	i = 0;
	while (i < num_elems)
	{
		if (!is_number(elems[i]))
			exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
		curr_val = ft_atol(elems[i]);
		if (curr_val > 2147483647 || curr_val < -2147483648)
			exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
		stack_a->values[i] = (int)curr_val;
		i ++;
	}
	if (i == 0)
		exit_elegantly(stack_a, stack_b, EMPTY_STACK);
	if (contains_duplicates(num_elems, stack_a->values))
		exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
}
