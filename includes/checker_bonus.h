/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:48:34 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 16:43:21 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libftprintf/includes/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef MAX_FD_OPEN
#  define MAX_FD_OPEN 1
# endif

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

char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
bool	found_nl(char *str);
size_t	ft_linelen(char *str);
void	get_stacks(int argc, char **argv,
			t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *to_stack, t_stack *from_stack);
void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	r_rotate(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	exit_elegantly(t_stack *stack_a,
			t_stack *stack_b, t_error error);

#endif
