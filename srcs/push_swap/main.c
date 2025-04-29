/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 15:09:51 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.values = NULL;
	stack_b.values = NULL;
	if (ac == 1)
		exit_elegantly(&stack_a, &stack_b, WRONG_INPUT_FORMAT);
	stack_a.id = 'a';
	stack_b.id = 'b';
	parse_args(ac, av, &stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	exit_elegantly(&stack_a, &stack_b, NONE);
	return (0);
}
