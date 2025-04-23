/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 14:17:19 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(int argc, int *stack_a)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		printf("%d\n", stack_a[i]);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, stack_a, stack_b);
	print_stack(argc, stack_a);
	return (0);
}
