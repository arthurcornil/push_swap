/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:49:22 by arcornil          #+#    #+#             */
/*   Updated: 2025/07/21 11:40:06 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef enum e_error
{
	NONE,
	DYNAMIC_ALLOCATION_FAILURE,
	WRONG_INPUT_FORMAT,
	TOO_MANY_ELEMENTS
}	t_error;

typedef struct s_node
{
	int				value;
	unsigned int	index;
}	t_node;

typedef struct s_stack
{
	t_node	*nodes;
	size_t	len;
	char	id;
}	t_stack;

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
