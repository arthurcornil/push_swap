/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:02:56 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/29 17:22:18 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*find_stack_with_id(char c, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->id == c)
		return (stack_a);
	return (stack_b);
}

void	execute_operation(char *str, t_stack *stack_a, t_stack *stack_b)
{
	t_stack *selected_stack;

	if (*str == 's')
	{
		str ++;
		if (*str == 's')
			ss(stack_a, stack_b);
		else
		{
			selected_stack = find_stack_with_id(*str, stack_a, stack_b);
			swap(selected_stack, true);
		}
	}
	else if (*str == 'r')
	{
		str ++;
		if (*str == 'a' || *str == 'b')
		{
			selected_stack = find_stack_with_id(*str, stack_a, stack_b);
			rotate(selected_stack, true);
		}
		else if (*str == 'r')
		{
			str ++;
			if (*str == '\n')
				rr(stack_a, stack_b);
			else if (*str == 'r')
				rrr(stack_a, stack_b);
			else
			{
				selected_stack = find_stack_with_id(*str, stack_a, stack_b);
				r_rotate(selected_stack, true);
			}
		}
	}
	else
	{
		str ++;
		if (*str == 'a')
			push(stack_a, stack_b);
		else
			push(stack_b, stack_a);
	}
}

#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	char	*str;

	stack_a.values = NULL;
	stack_b.values = NULL;
	if (ac == 1)
		exit_elegantly(&stack_a, &stack_b, WRONG_INPUT_FORMAT);
	stack_a.id = 'a';
	stack_b.id = 'b';
	parse_args(ac, av, &stack_a, &stack_b);
	while ((str = get_next_line(0)))
		execute_operation(str, &stack_a, &stack_b);
	if (is_stack_sorted(&stack_a))
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
