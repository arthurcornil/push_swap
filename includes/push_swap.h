/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:49:22 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:44:21 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/includes/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_error
{
	NONE,
	DYNAMIC_ALLOCATION_FAILURE,
	WRONG_INPUT_FORMAT,
	EMPTY_STACK
}	t_error;

typedef struct s_stack
{
	int		*values;
	size_t	len;
	char	id;
}	t_stack;

typedef struct s_cheapest_operation
{
	size_t	origin_index;
	size_t	target_index;
}	t_cheapest_operation;

typedef struct s_rotate_both_stacks_args
{
	t_stack	*from;
	t_stack	*to;
	size_t	*cost_a;
	size_t	*cost_b;
	bool	top_half;
}	t_rotate_both_stacks_args;

void			get_stacks(int argc, char **argv,
					t_stack *stack_a, t_stack *stack_b);
void			swap(t_stack *stack, bool log);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			push(t_stack *to_stack, t_stack *from_stack);
void			rotate(t_stack *stack, bool log);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			r_rotate(t_stack *stack, bool log);
void			rrr(t_stack *stack_a, t_stack *stack_b);
void			push_swap(t_stack *stack_a, t_stack *stack_b);
void			exit_elegantly(t_stack *stack_a,
					t_stack *stack_b, t_error error);
bool			is_stack_sorted(t_stack *stack);
void			turk_sort(t_stack *stack_a, t_stack *stack_b);
void			pico_sort(t_stack *stack);
size_t			get_extreme_index(t_stack *stack, bool find_min);
unsigned int	get_cost(size_t	index_a, size_t index_b,
					t_stack *stack_a, t_stack *stack_b);
bool			is_target_valid(int potential_target, int origin, bool from_a);
bool			is_better_target(int current_val, int best_val, bool from_a);
bool			is_first_valid_target(int current_val,
					int origin_val, bool from_a);
size_t			get_smallest(size_t a, size_t b);
size_t			get_highest(size_t a, size_t b);
size_t			get_extreme_index(t_stack *stack, bool find_min);
size_t			get_target_index(t_stack *stack, int origin);
unsigned int	get_cost_to_top(size_t index, t_stack *stack);
void			(*operate(size_t index,
						t_stack *stack))(t_stack *stack, bool log);
bool			is_in_top_half(size_t index, t_stack *stack);
void			get_num_to_top(size_t index, t_stack *stack);
void			handle_errors(unsigned int num_elems, char **elems,
					t_stack *stack_a, t_stack *stack_b);

#endif
