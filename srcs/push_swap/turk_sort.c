/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:01:16 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:26:56 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_both_stacks(t_rotate_both_stacks_args args)
{
	if (args.top_half)
	{
		while (*(args.cost_a) > 0 && *(args.cost_b) > 0)
		{
			rr(args.from, args.to);
			(*(args.cost_a))--;
			(*(args.cost_b))--;
		}
		return ;
	}
	while (*(args.cost_a) > 0 && *(args.cost_b) > 0)
	{
		rrr(args.from, args.to);
		(*(args.cost_a))--;
		(*(args.cost_b))--;
	}
}

static void	rotate_single_stack(t_stack *stack, size_t *cost, bool top_half)
{
	if (top_half)
	{
		while (*cost > 0)
		{
			rotate(stack, true);
			(*cost)--;
		}
		return ;
	}
	while (*cost > 0)
	{
		r_rotate(stack, true);
		(*cost)--;
	}
}

void	make_operations(t_stack *from, t_stack *to, t_cheapest_operation co)
{
	size_t	cost_a;
	size_t	cost_b;
	bool	a_is_top_half;
	bool	b_is_top_half;

	cost_a = get_cost_to_top(co.origin_index, from);
	cost_b = get_cost_to_top(co.target_index, to);
	a_is_top_half = is_in_top_half(co.origin_index, from);
	b_is_top_half = is_in_top_half(co.target_index, to);
	if (a_is_top_half == b_is_top_half)
		rotate_both_stacks((t_rotate_both_stacks_args){
			from, to, &cost_a, &cost_b, a_is_top_half});
	rotate_single_stack(from, &cost_a, a_is_top_half);
	rotate_single_stack(to, &cost_b, b_is_top_half);
	push(to, from);
}

void	push_in_optimized_order(t_stack *from, t_stack *to)
{
	unsigned int			cheapest_cost;
	unsigned int			curr_cost;
	size_t					i;
	size_t					curr_target_index;
	t_cheapest_operation	cheapest_operation;

	i = 0;
	cheapest_cost = UINT_MAX;
	while (i < from->len)
	{
		curr_target_index = get_target_index(to, from->values[i]);
		curr_cost = get_cost(i, curr_target_index, from, to);
		if (curr_cost < cheapest_cost)
		{
			cheapest_cost = curr_cost;
			cheapest_operation = (t_cheapest_operation){
				i,
				curr_target_index
			};
		}
		i ++;
	}
	make_operations(from, to, cheapest_operation);
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_index;

	push(stack_b, stack_a);
	push(stack_b, stack_a);
	while (stack_a->len > 3)
		push_in_optimized_order(stack_a, stack_b);
	pico_sort(stack_a);
	while (stack_b->len)
		push_in_optimized_order(stack_b, stack_a);
	min_index = get_extreme_index(stack_a, true);
	get_num_to_top(min_index, stack_a);
}
