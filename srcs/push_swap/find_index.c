/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:15:35 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:52:43 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	get_extreme_index(t_stack *stack, bool find_min)
{
	size_t	extreme_idx;
	size_t	i;

	extreme_idx = 0;
	i = 0;
	while (i < stack->len)
	{
		if ((find_min && stack->values[i] < stack->values[extreme_idx])
			|| (!find_min && stack->values[i] > stack->values[extreme_idx]))
			extreme_idx = i;
		i ++;
	}
	return (extreme_idx);
}

static size_t	find_best_target(t_stack *stack, int origin, bool from_a)
{
	size_t	i;
	size_t	target_idx;
	bool	target_found;

	i = 0;
	target_idx = 0;
	target_found = false;
	while (i < stack->len)
	{
		if (is_target_valid(stack->values[i], origin, from_a))
		{
			if ((target_found && is_better_target(stack->values[i],
						stack->values[target_idx], from_a))
				|| (!target_found && is_first_valid_target(stack->values[i],
						origin, from_a)))
			{
				target_idx = i;
				target_found = true;
			}
		}
		i++;
	}
	if (!target_found)
		return (SIZE_MAX);
	return (target_idx);
}

size_t	get_target_index(t_stack *stack, int origin)
{
	size_t	target_idx;
	bool	from_a;

	from_a = (stack->id == 'b');
	target_idx = find_best_target(stack, origin, from_a);
	if (target_idx == SIZE_MAX)
		target_idx = get_extreme_index(stack, !from_a);
	return (target_idx);
}
