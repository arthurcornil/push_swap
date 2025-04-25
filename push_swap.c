/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:06:43 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/25 18:47:11 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack *stack)
{
	size_t	highest_value_index;
	size_t	i;

	i = 0;
	highest_value_index = 0;
	while (i < stack->len)
	{
		if (stack->values[i] > stack->values[highest_value_index])
			highest_value_index = i;
		i ++;
	}
	if (highest_value_index == 0)
		rotate(stack, true);
	else if (highest_value_index == 1)
		r_rotate(stack, true);
	if (stack->values[0] > stack->values[1])
		swap(stack, true);
}

size_t get_next_value_index(int value, t_stack *stack)
{
	size_t	i;
	int		lowest_value_index;
	size_t	lowest_upper_sibling_index;
	bool	found;

	i = 0;
	found = false;
	lowest_value_index = 0;
	while (i < stack->len)
	{
		if (stack->values[i] > value && (!found || (found && stack->values[i] < stack->values[lowest_upper_sibling_index])))
		{
			lowest_upper_sibling_index = i;
			if (!found)
				found = true;
		}
		if (!found && stack->values[i] < stack->values[lowest_value_index])
			lowest_value_index = i;
		i ++;
	}
	if (!found)
		return (lowest_value_index);
	return (lowest_upper_sibling_index);
}

unsigned int	get_cost_to_top(t_stack *stack, size_t index)
{
	if (index > stack->len / 2)
		return (stack->len - index);
	else
		return (index);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, size_t a_index, size_t b_index)
{
	int	stack_a_top_target = stack_a->values[a_index];
	int	stack_b_top_target = stack_b->values[b_index];

	if (a_index > stack_a->len / 2)
	{
		while (stack_a->values[0] != stack_a_top_target)
			r_rotate(stack_a, true);
	}
	else
	{
		while (stack_a->values[0] != stack_a_top_target)
			rotate(stack_a, true);
	}
	if (b_index > stack_b->len / 2)
	{
		while (stack_b->values[0] != stack_b_top_target)
			r_rotate(stack_b, true);
	}
	else
	{
		while (stack_b->values[0] != stack_b_top_target)
			rotate(stack_b, true);
	}
	push(stack_a, stack_b);
}

void	finish(t_stack *stack)
{
	size_t	i;
	size_t	lowest_value_index;
	int		lowest_value;

	i = 0;
	lowest_value_index = 0;
	while (i < stack->len)
	{
		if (stack->values[i] < lowest_value)
		{
			lowest_value_index = i;
			lowest_value = stack->values[i];
		}
		i ++;
	}
	if (lowest_value_index > stack->len / 2)
	{
		while (stack->values[0] != lowest_value)
			r_rotate(stack, true);
	}
	else
	{
		while (stack->values[0] != lowest_value)
			rotate(stack, true);
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	size_t			i;
	size_t			next_value_index;
	unsigned int	min_cost_found;
	unsigned int	curr_cost;
	size_t			min_cost_a_index_target;
	size_t			min_cost_b_index_target;

	while (stack_a->len > 3)
		push(stack_b, stack_a);
	tiny_sort(stack_a);
	if (stack_a->len + stack_b->len <= 3)
		return ;
	i = 0;
	min_cost_found = UINT_MAX;
	while (stack_b->len > 0)
	{
		next_value_index = get_next_value_index(stack_b->values[i], stack_a);
		curr_cost = get_cost_to_top(stack_a, next_value_index) + get_cost_to_top(stack_b, i);
		if (curr_cost < min_cost_found)
		{
			min_cost_found = curr_cost;
			min_cost_a_index_target = next_value_index;
			min_cost_b_index_target = i;
		}
		if (curr_cost == 1)
		{
			b_to_a(stack_a, stack_b, next_value_index, i);
			i = 0;
			continue ;
		}
		else if (i == stack_b->len - 1)
		{
			b_to_a(stack_a, stack_b, min_cost_a_index_target, min_cost_b_index_target);
			i = 0;
			continue ;
		}
		i ++;
	}
	finish(stack_a);
}
