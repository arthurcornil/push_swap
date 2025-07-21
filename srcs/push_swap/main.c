/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/07/21 11:42:22 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->len) 
	{
		printf("%u -> %d\n", stack->nodes[i].index, stack->nodes[i].value);
		i ++;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.nodes = NULL;
	stack_b.nodes = NULL;
	if (ac == 1)
		exit_elegantly(&stack_a, &stack_b, WRONG_INPUT_FORMAT);
	stack_a.id = 'a';
	stack_b.id = 'b';
	get_stacks(ac, av, &stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	//print_stack(&stack_a);
	exit_elegantly(&stack_a, &stack_b, NONE);
	return (0);
}
