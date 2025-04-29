/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:49:22 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 12:44:32 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

typedef enum e_error
{
	NONE,
	DYNAMIC_ALLOCATION_FAILURE,
	WRONG_INPUT_FORMAT
}	t_error;

typedef struct s_stack
{
	int		*values;
	size_t	len;
	char	id;
}	t_stack;

t_error	parse_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack, bool log);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *to_stack, t_stack *from_stack);
void	rotate(t_stack *stack, bool log);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	r_rotate(t_stack *stack, bool log);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	ft_putstr_fd(int fd, char *str);

#endif
