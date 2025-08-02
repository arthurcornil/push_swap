/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:49:22 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/01 10:44:09 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/includes/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# define PICO_SORT_LEN 3
# define MINI_SORT_LEN 15

typedef enum e_error
{
	NONE,
	DYNAMIC_ALLOCATION_FAILURE,
	WRONG_INPUT_FORMAT,
	TOO_MANY_ELEMENTS,
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

void	get_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack, bool log);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *to_stack, t_stack *from_stack);
void	rotate(t_stack *stack, bool log);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	r_rotate(t_stack *stack, bool log);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	exit_elegantly(t_stack *stack_a, t_stack *stack_b, t_error error);
bool	is_stack_sorted(t_stack *stack);

#endif
