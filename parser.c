/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:51:46 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 14:16:56 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static int	ft_atoi(const char *str)
{
	bool	is_negative;
	int		result;

	is_negative = false;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = true;
		str ++;
	}
	result = 0;
	while (ft_isnum(*str))
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

bool	can_convert_str_to_int(char *str)
{
	if (*str == '-' || *str == '+')
		str ++;
	while (*str)
	{
		if (!ft_isnum(*str))
			return (false);
		str ++;
	}
	return (true);
}

bool	are_args_valid(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!can_convert_str_to_int(argv[i]))
			return (false);
		i ++;
	}
	return (true);
}

bool	parse_args(int argc, char **argv, int *stack_a, int *stack_b)
{
	int	i;

	if (!are_args_valid(argc, argv))
		return (false);
	stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack_a)
		return (false);
	stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack_b)
	{
		free(stack_a);
		return (false);
	}
	i = 0;
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i]);
		i ++;
	}
	return (true);
}
