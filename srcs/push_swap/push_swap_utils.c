/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:09:18 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 16:59:50 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_stack_sorted(t_stack *stack)
{
	size_t	i;
	int		prev_num;

	prev_num = stack->values[0];
	i = 1;
	while (i < stack->len)
	{
		if (prev_num > stack->values[i])
			return (false);
		prev_num = stack->values[i];
		i ++;
	}
	return (true);
}

