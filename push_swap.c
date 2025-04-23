/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:06:43 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 18:55:55 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

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

size_t	get_next_value_index(int value, t_stack *stack)
{
	size_t	i;
	size_t	min_index;

	i = 0;
	min_index = 0;
	while (i < stack->len)
	{
		if (stack->values[i] > value)
			return (i);
		else if (stack->values[i] < stack->values[min_index])
			min_index = i;
		i ++;
	}
	return (min_index);
}

unsigned int	get_cost_to_top(t_stack *stack, size_t index)
{
	if (index >= stack->len / 2)
		return (stack->len - index);
	else
		return (index);
}

void	b_to_a(t_stack *stack_a, t_stack *stack_b, size_t a_index, size_t b_index)
{
	
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	size_t			i;
	size_t			next_value_index;
	unsigned int	min_num_operations;
	unsigned int	curr_num_operations;

	while (stack_a->len > 3)
		push(stack_b, stack_a);
	tiny_sort(stack_a);
	if (stack_a->len + stack_b->len <= 3)
		return ;
	i = 0;
	min_num_operations = UINT_MAX;
	while (i < stack_b->len)
	{
		next_value_index = get_next_value_index(stack_b->values[i], stack_a);
		curr_num_operations = get_num_operations();
		if (curr_num_operations < min_num_operations)
			min_num_operations = curr_num_operations;
		if (curr_num_operations == 1)
			b_to_a(stack_a, stack_b, next_value_index, i);
		i ++;
	}
}
