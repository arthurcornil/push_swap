/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:42:12 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 12:45:54 by arcornil         ###   ########.fr       */
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

//void	print_stack(t_stack *stack_a)
//{
//	size_t	i;
//
//	i = 0;
//	printf("\n");
//	while (i < stack_a->len)
//	{
//		printf("%d\n", stack_a->values[i]);
//		i ++;
//	}
//}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (1);
	stack_a.id = 'a';
	stack_b.id = 'b';
	stack_a.values = NULL;
	stack_b.values = NULL;
	parse_args(ac, av, &stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	return (0);
}
