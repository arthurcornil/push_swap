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

#include "../../includes/push_swap.h"

void	r_rotate(t_stack *stack, bool log)
{
	size_t	i;
	int		tmp;

	i = stack->len - 1;
	tmp = stack->values[stack->len - 1];
	while (i > 0)
	{
		stack->values[i] = stack->values[i - 1];
		i --;
	}
	stack->values[0] = tmp;
	if (log)
		ft_printf("rr%c\n", stack->id);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a, false);
	r_rotate(stack_b, false);
	ft_printf("rrr\n");
}
