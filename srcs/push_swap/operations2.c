/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:41:58 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 16:44:44 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	r_rotate(t_stack *stack, bool log)
{
	size_t	i;
	t_node	tmp_node;

	i = stack->len - 1;
	tmp_node = stack->nodes[stack->len - 1];
	while (i > 0)
	{
		stack->nodes[i] = stack->nodes[i - 1];
		i --;
	}
	stack->nodes[0] = tmp_node;
	if (log)
		printf("rr%c\n", stack->id);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a, false);
	r_rotate(stack_b, false);
	printf("rrr\n");
}
