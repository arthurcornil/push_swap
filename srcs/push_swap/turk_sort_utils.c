/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:03:02 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:17:53 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_in_top_half(size_t index, t_stack *stack)
{
	return (index <= stack->len / 2);
}

unsigned int	get_cost_to_top(size_t index, t_stack *stack)
{
	if (is_in_top_half(index, stack))
		return (index);
	return (stack->len - index);
}

void	(*operate(size_t index, t_stack *stack))(t_stack *stack, bool log)
{
	if (is_in_top_half(index, stack))
		return (rotate);
	return (r_rotate);
}

void	get_num_to_top(size_t index, t_stack *stack)
{
	unsigned int	cost;
	unsigned int	i;

	cost = get_cost_to_top(index, stack);
	i = 0;
	while (i < cost)
	{
		(operate(index, stack))(stack, true);
		i ++;
	}
}

unsigned int	get_cost(size_t	index_a, size_t index_b,
		t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	cost_a;
	unsigned int	cost_b;

	cost_a = get_cost_to_top(index_a, stack_a);
	cost_b = get_cost_to_top(index_b, stack_b);
	if ((is_in_top_half(index_a, stack_a) && is_in_top_half(index_b, stack_b))
		|| (!is_in_top_half(index_a, stack_a)
			&& !is_in_top_half(index_b, stack_b)))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}
