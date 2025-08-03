/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:29:57 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:17:03 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdint.h>

void	pico_sort(t_stack *stack)
{
	size_t	highest_value_index;
	size_t	i;

	i = 0;
	highest_value_index = 0;
	while (i < stack->len)
	{
		if (stack->values[i] > stack->values[highest_value_index])
			highest_value_index = i;
		i++;
	}
	if (highest_value_index == 0)
		rotate(stack, true);
	else if (highest_value_index == 1)
		r_rotate(stack, true);
	if (stack->values[0] > stack->values[1])
		swap(stack, true);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 1 || is_stack_sorted(stack_a))
		return ;
	else if (stack_a->len == 2)
		swap(stack_a, true);
	else if (stack_a->len == PICO_SORT_LEN)
		pico_sort(stack_a);
	else
		turk_sort(stack_a, stack_b);
}
