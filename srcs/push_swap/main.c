/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/08/03 08:29:32 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (1);
	stack_a.id = 'a';
	stack_b.id = 'b';
	get_stacks(ac, av, &stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	exit_elegantly(&stack_a, &stack_b, NONE);
	return (0);
}
