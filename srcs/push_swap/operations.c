/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:27:21 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 07:59:12 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *stack, bool log)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	tmp = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = tmp;
	if (log)
		ft_printf("s%c\n", stack->id);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, false);
	swap(stack_b, false);
	ft_printf("ss\n");
}

void	push(t_stack *to_stack, t_stack *from_stack)
{
	size_t	i;

	if (!from_stack->len)
		return ;
	i = to_stack->len;
	while (i >= 1)
	{
		to_stack->values[i] = to_stack->values[i - 1];
		i --;
	}
	to_stack->values[0] = from_stack->values[0];
	i = 0;
	while (i < (from_stack->len) - 1)
	{
		from_stack->values[i] = from_stack->values[i + 1];
		i ++;
	}
	to_stack->len ++;
	from_stack->len --;
	ft_printf("p%c\n", to_stack->id);
}

void	rotate(t_stack *stack, bool log)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = stack->values[0];
	while (i < (stack->len) - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i ++;
	}
	stack->values[stack->len - 1] = tmp;
	if (log)
		ft_printf("r%c\n", stack->id);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, false);
	rotate(stack_b, false);
	ft_printf("rr\n");
}
