/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:06:43 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 17:16:41 by arcornil         ###   ########.fr       */
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

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len >= 3)
	{
		tiny_sort(stack_a);
		return ;
	}
}
