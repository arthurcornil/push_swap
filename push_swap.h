/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:49:22 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 14:57:30 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef enum e_error
{
	NONE,
	WRONG_INT_FORMAT,
	DYNAMIC_ALLOCATION_FAILURE,
	DUPLICATE_ENTRIES
}	t_error;

t_error	parse_args(int argc, char **argv, int **stack_a, int **stack_b);

#endif
