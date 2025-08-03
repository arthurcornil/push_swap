/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:51:46 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:37:33 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exit_elegantly(t_stack *stack_a, t_stack *stack_b, t_error error)
{
	if (stack_a->values)
		free(stack_a->values);
	if (stack_b->values)
		free(stack_b->values);
	if (error == WRONG_INPUT_FORMAT || error == EMPTY_STACK)
		ft_putstr_fd("Error\n", 2);
	else if (error != NONE)
		exit(1);
	exit(0);
}

void	get_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	num_elems;
	char			**elems;

	if (argc == 2)
	{
		elems = ft_split(argv[1], ' ');
		num_elems = 0;
		while (elems[num_elems])
			num_elems ++;
	}
	else
	{
		elems = argv + 1;
		num_elems = argc - 1;
	}
	stack_a->values = (int *)malloc(sizeof(int) * (num_elems));
	if (!stack_a->values)
		exit_elegantly(stack_a, stack_b, DYNAMIC_ALLOCATION_FAILURE);
	stack_b->values = (int *)malloc(sizeof(int) * (num_elems));
	if (!stack_b->values)
		exit_elegantly(stack_a, stack_b, DYNAMIC_ALLOCATION_FAILURE);
	handle_errors(num_elems, elems, stack_a, stack_b);
	stack_a->len = num_elems;
	stack_b->len = 0;
}
