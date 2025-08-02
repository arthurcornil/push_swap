/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 10:29:57 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/01 22:17:50 by arcornil         ###   ########.fr       */
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

bool	is_target_valid(int potential_target, int origin, bool from_a)
{
	if (from_a)
		return (potential_target < origin);
	return (potential_target > origin);
}

static bool	is_better_target(int current_val, int best_val, bool from_a)
{
	if (from_a)
		return (current_val > best_val);
	else
		return (current_val < best_val);
}

static bool	is_first_valid_target(int current_val, int origin_val, bool from_a)
{
	if (from_a)
		return (current_val < origin_val);
	else
		return (current_val > origin_val);
}

size_t	get_target_index(t_stack *stack, int origin)
{
	size_t	i;
	size_t	target_idx;
	bool	target_found;
	bool	from_a;

	i = 0;
	target_idx = 0;
	target_found = false;
	from_a = false;
	if (stack->id == 'b')
		from_a = true;
	while (i < stack->len)
	{
		if (!is_target_valid(stack->values[i], origin, from_a))
		{
			i ++;
			continue ;
		}
		if ((target_found && is_better_target(stack->values[i],
			stack->values[target_idx], from_a))
			|| (!target_found && is_first_valid_target(stack->values[i],
	origin, from_a)))
		{
			target_idx = i;
			if (!target_found)
				target_found = true;
		}
		i ++;
	}
	if (!target_found)
		target_idx = get_extreme_index(stack, !from_a);
	return (target_idx);
}

bool	is_in_top_half(size_t index, t_stack *stack)
{
	return (index <= stack->len / 2);
}

unsigned int	get_cost_to_top(size_t index, t_stack *stack)
{
	if (is_in_top_half(index, stack))
		return (index);
	return (stack->len - index);
}

size_t	get_smallest(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	get_highest(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

void	(*operate(size_t index, t_stack *stack))(t_stack *stack, bool log)
{
	if (is_in_top_half(index, stack))
		return (rotate);
	return (r_rotate);
}

unsigned int	get_cost(size_t	index_a, size_t index_b,
		t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	cost_a;
	unsigned int	cost_b;

	cost_a = get_cost_to_top(index_a, stack_a);
	cost_b = get_cost_to_top(index_b, stack_b);
	if ((is_in_top_half(index_a, stack_a) && is_in_top_half(index_b, stack_b))
		|| (!is_in_top_half(index_a, stack_a)
			&& !is_in_top_half(index_b, stack_b)))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	get_num_to_top(size_t index, t_stack *stack)
{
	unsigned int	cost;
	unsigned int	i;

	cost = get_cost_to_top(index, stack);
	i = 0;
	while (i < cost)
	{
		(operate(index, stack))(stack, true);
		i ++;
	}
}

static void	rotate_both_stacks(t_stack *from, t_stack *to,
		size_t *cost_a, size_t *cost_b, bool top_half)
{
	if (top_half)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			rr(from, to);
			(*cost_a)--;
			(*cost_b)--;
		}
		return ;
	}
	while (*cost_a > 0 && *cost_b > 0)
	{
		rrr(from, to);
		(*cost_a)--;
		(*cost_b)--;
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
	{
		rotate_both_stacks(from, to, &cost_a, &cost_b, a_is_top_half);
		rotate_single_stack(from, &cost_a, a_is_top_half);
		rotate_single_stack(to, &cost_b, b_is_top_half);
	}
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
	while (stack_a->len > PICO_SORT_LEN)
		push_in_optimized_order(stack_a, stack_b);
	pico_sort(stack_a);
	while (stack_b->len)
		push_in_optimized_order(stack_b, stack_a);
	min_index = get_extreme_index(stack_a, true);
	get_num_to_top(min_index, stack_a);
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
