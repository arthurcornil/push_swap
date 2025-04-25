/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/25 13:43:36 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_putstr_fd(int fd, char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len ++;
	write(fd, str, len);
}

void	print_stack(t_stack *stack_a)
{
	int	i;

	i = 0;
	printf("stack_%c\n", stack_a->id);
	while (i < stack_a->len)
	{
		printf("%d\n", stack_a->values[i]);
		i ++;
	}
	printf("--------\nlen: %zu", stack_a->len);
	printf("\n\n");
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_error	parsing_error;

	if (ac == 1)
		return (1);
	stack_a.id = 'a';
	stack_b.id = 'b';
	parsing_error = parse_args(ac, av, &stack_a, &stack_b);
	if (parsing_error != NONE)
	{
		if (parsing_error == DUPLICATE_ENTRIES)
		{
			free(stack_a.values);
			free(stack_b.values);
		}
		ft_putstr_fd(2, "Error");
		return (1);
	}
	push_swap(&stack_a, &stack_b);
	print_stack(&stack_a);
	print_stack(&stack_b);
	return (0);
}
