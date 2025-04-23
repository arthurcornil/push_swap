/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/23 14:57:22 by arcornil         ###   ########.fr       */
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
	t_error	parsing_error;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	parsing_error = parse_args(argc, argv, &stack_a, &stack_b);
	if (parsing_error != NONE)
	{
		if (parsing_error == DUPLICATE_ENTRIES)
		{
			free(stack_a);
			free(stack_b);
		}
		ft_putstr_fd(2, "Error");
		return (1);
	}
	print_stack(argc, stack_a);
	return (0);
}
