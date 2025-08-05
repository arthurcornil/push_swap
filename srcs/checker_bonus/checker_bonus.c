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

#include "../../includes/checker_bonus.h"

bool	is_stack_sorted(t_stack *stack)
{
	size_t	i;
	int		prev_num;

	prev_num = stack->values[0];
	i = 1;
	while (i < stack->len)
	{
		if (prev_num > stack->values[i])
			return (false);
		prev_num = stack->values[i];
		i ++;
	}
	return (true);
}

t_stack	*find_stack_with_id(char c, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->id == c)
		return (stack_a);
	return (stack_b);
}

void	handle_rotate(char **str, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*selected_stack;

	(*str)++;
	if (**str == 'a' || **str == 'b')
	{
		selected_stack = find_stack_with_id(**str, stack_a, stack_b);
		rotate(selected_stack);
	}
	else if (**str == 'r')
	{
		(*str)++;
		if (**str == '\n')
			rr(stack_a, stack_b);
		else if (**str == 'r')
			rrr(stack_a, stack_b);
		else
		{
			selected_stack = find_stack_with_id(**str, stack_a, stack_b);
			r_rotate(selected_stack);
		}
	}
}

void	execute_operation(char *str, t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*selected_stack;

	if (*str == 's')
	{
		str ++;
		if (*str == 's')
			ss(stack_a, stack_b);
		else
		{
			selected_stack = find_stack_with_id(*str, stack_a, stack_b);
			swap(selected_stack);
		}
	}
	else if (*str == 'r')
		handle_rotate(&str, stack_a, stack_b);
	else
	{
		str ++;
		if (*str == 'a')
			push(stack_a, stack_b);
		else
			push(stack_b, stack_a);
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*str;

	stack_a.values = NULL;
	stack_b.values = NULL;
	if (ac == 1)
		exit_elegantly(&stack_a, &stack_b, WRONG_INPUT_FORMAT);
	stack_a.id = 'a';
	stack_b.id = 'b';
	get_stacks(ac, av, &stack_a, &stack_b);
	while (true)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		execute_operation(str, &stack_a, &stack_b);
		free(str);
	}
	if (is_stack_sorted(&stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit_elegantly(&stack_a, &stack_b, NONE);
	return (0);
}
