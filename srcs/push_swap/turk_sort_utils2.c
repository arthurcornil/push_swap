/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 08:12:11 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:44:19 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	is_target_valid(int potential_target, int origin, bool from_a)
{
	if (from_a)
		return (potential_target < origin);
	return (potential_target > origin);
}

bool	is_better_target(int current_val, int best_val, bool from_a)
{
	if (from_a)
		return (current_val > best_val);
	else
		return (current_val < best_val);
}

bool	is_first_valid_target(int current_val, int origin_val, bool from_a)
{
	if (from_a)
		return (current_val < origin_val);
	else
		return (current_val > origin_val);
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
