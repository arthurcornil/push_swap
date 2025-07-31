/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:27:21 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 17:22:19 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack *stack, bool log)
{
	t_node	tmp_node;

	if (stack->len < 2)
		return ;
	tmp_node = stack->nodes[0];
	stack->nodes[0] = stack->nodes[1];
	stack->nodes[1] = tmp_node;
	if (log)
		printf("s%c\n", stack->id);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, false);
	swap(stack_b, false);
	printf("ss\n");
}

void	push(t_stack *to_stack, t_stack *from_stack)
{
	size_t	i;

	if (!from_stack->len)
		return ;
	i = to_stack->len;
	while (i >= 1)
	{
		to_stack->nodes[i] = to_stack->nodes[i - 1];
		i --;
	}
	to_stack->nodes[0] = from_stack->nodes[0];
	i = 0;
	while (i < (from_stack->len) - 1)
	{
		from_stack->nodes[i] = from_stack->nodes[i + 1];
		i ++;
	}
	to_stack->len ++;
	from_stack->len --;
	printf("p%c\n", to_stack->id);
}

void	rotate(t_stack *stack, bool log)
{
	size_t	i;
	t_node	tmp_node;

	i = 0;
	tmp_node = stack->nodes[0];
	while (i < (stack->len) - 1)
	{
		stack->nodes[i] = stack->nodes[i + 1];
		i ++;
	}
	stack->nodes[stack->len - 1] = tmp_node;
	if (log)
		printf("r%c\n", stack->id);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, false);
	rotate(stack_b, false);
	printf("rr\n");
}
