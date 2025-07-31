/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:51:46 by arcornil          #+#    #+#             */
/*   Updated: 2025/07/21 11:54:37 by arcornil         ###   ########.fr       */
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

bool	contains_duplicates(int size, t_node *nodes)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (nodes[i].value == nodes[j].value)
				return (true);
			j ++;
		}
		i ++;
	}
	return (false);
}

void	exit_elegantly(t_stack *stack_a, t_stack *stack_b, t_error error)
{
	if (stack_a->nodes)
		free(stack_a->nodes);
	if (stack_b->nodes)
		free(stack_b->nodes);
	if (error == WRONG_INPUT_FORMAT || error == TOO_MANY_ELEMENTS)
		ft_putstr_fd("Error\n", 2);
	else if (error != NONE)
		exit(1);
	exit(0);
}

void	get_indeces(t_stack *stack)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	curr_index;

	i = 0;
	while (i < stack->len)
	{
		curr_index = 0;
		j = 0;
		while (j < stack->len)
		{
			if (i == j)
			{
				j ++;
				continue ;
			}
			else if (stack->nodes[i].value > stack->nodes[j].value)
				curr_index ++;
			j ++;
		}
		stack->nodes[i].index = curr_index;
		i ++;
	}
}

void	get_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	unsigned int				i;
	long int		curr_val;
	unsigned int	num_elems;
	char			**elems;

	if ((unsigned int)(argc - 1) > UINT_MAX)
		exit_elegantly(stack_a, stack_b, TOO_MANY_ELEMENTS);
	if (argc == 2)
	{
		elems = ft_split(argv[1], ' ');
		num_elems = 0;
		while (elems[num_elems])
			num_elems ++;
	}
	else
	{
		elems = argv + 1;
		num_elems = argc - 1;
	}
	stack_a->nodes = (t_node *)malloc(sizeof(t_node) * (num_elems));
	if (!stack_a->nodes)
		exit_elegantly(stack_a, stack_b, DYNAMIC_ALLOCATION_FAILURE);
	stack_b->nodes = (t_node *)malloc(sizeof(t_node) * (num_elems));
	if (!stack_b->nodes)
		exit_elegantly(stack_a, stack_b, DYNAMIC_ALLOCATION_FAILURE);
	i = 0;
	while (i < num_elems)
	{
		if (!is_number(elems[i]))
			exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
		curr_val = ft_atol(elems[i]);
		if (curr_val > 2147483647 || curr_val < -2147483648)
			exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
		stack_a->nodes[i].value = (int) curr_val;
		i ++;
	}
	if (contains_duplicates(argc - 1, stack_a->nodes))
		exit_elegantly(stack_a, stack_b, WRONG_INPUT_FORMAT);
	stack_a->len = num_elems;
	stack_b->len = 0;
	get_indeces(stack_a);
}
