/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:14:10 by arcornil          #+#    #+#             */
/*   Updated: 2025/07/21 11:54:39 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pico_sort(t_stack *stack)
{
	size_t	highest_value_index;
	size_t	i;

	i = 0;
	highest_value_index = 0;
	while (i < stack->len)
	{
		if (stack->nodes[i].value > stack->nodes[highest_value_index].value)
			highest_value_index = i;
		i ++;
	}
	if (highest_value_index == 0)
		rotate(stack, true);
	else if (highest_value_index == 1)
		r_rotate(stack, true);
	if (stack->nodes[0].value > stack->nodes[1].value)
		swap(stack, true);
}

void mini_sort(t_stack *stack_a, t_stack *stack_b)
{
    int num_to_push;
    int small_index;
    unsigned int i;

	num_to_push = stack_a->len - 3;
	small_index = 0;
    while (num_to_push > 0)
    {
		i = 0;
        while (i < stack_a->len)
        {
            if (stack_a->nodes[i].index == (unsigned int)small_index)
                break;
            i++;
        }
        if (i <= stack_a->len / 2)
        {
            while (i-- > 0)
                rotate(stack_a, true);
        }
        else
        {
            unsigned int j = stack_a->len - i;
            while (j-- > 0)
                r_rotate(stack_a, true);
        }
        push(stack_b, stack_a);
        small_index++;
        num_to_push--;
    }
    pico_sort(stack_a);
    while (stack_b->len > 0)
        push(stack_a, stack_b);
}

int	get_nth_bit(unsigned int num, unsigned int n)
{
	return ((num >> n) & 1);
}

void	order_by_nth_bit(t_stack *stack_a, t_stack *stack_b, unsigned int stack_a_len, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < stack_a_len)
	{
		if (get_nth_bit(stack_a->nodes[0].index, n) == 0)
			push(stack_b, stack_a);
		else
			rotate(stack_a, true);
		i ++;
	}
	while (stack_b->len > 0)
		push(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b, unsigned int	max_bits)
{
	unsigned int	i;
	unsigned int	stack_a_len;

	i = 0;
	stack_a_len = stack_a->len;
	while (i < max_bits)
	{
		if (is_stack_sorted(stack_a))
			return ;
		order_by_nth_bit(stack_a, stack_b, stack_a_len, i);
		i ++;
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	highest_index;
	unsigned int	i;
	unsigned int	max_bits;

	if (stack_a->len <= 1 || is_stack_sorted(stack_a))
		return ;
	if (stack_a->len == 2)
		swap(stack_a, true);
	else if (stack_a->len == PICO_SORT_LEN)
		pico_sort(stack_a);
	else if (stack_a->len > PICO_SORT_LEN && stack_a->len <= MINI_SORT_LEN)
		mini_sort(stack_a, stack_b);
	else
	{
		i = 0;
		highest_index = 0;
		while (i < stack_a->len)
		{
			if (stack_a->nodes[i].index > highest_index)
				highest_index = stack_a->nodes[i].index;
			i ++;
		}
		max_bits = 1;
		while ((highest_index >> max_bits) != 0)
			max_bits ++;
		radix_sort(stack_a, stack_b, max_bits);
	}
}
