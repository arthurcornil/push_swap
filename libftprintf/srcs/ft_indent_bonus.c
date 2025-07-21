/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:54:36 by arcornil          #+#    #+#             */
/*   Updated: 2025/03/17 14:25:30 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_format_precision(t_print *tab, int len_elem)
{
	if (tab->sign == 2)
		write(1, "-", 1);
	if (tab->sign == 2 && tab->precision > len_elem && !tab->is_zero)
		tab->length ++;
	else if (tab->sign == 1)
		tab->length += write(1, "+", 1);
	while (tab->precision > len_elem)
	{
		tab->length += write(1, "0", 1);
		tab->precision --;
	}
}

void	ft_right_indent(t_print *tab, int len)
{
	int	width;

	width = tab->width;
	while (width > len)
	{
		if (!tab->is_zero)
			tab->length += write(1, " ", 1);
		else if (tab->is_zero)
			tab->length += write(1, "0", 1);
		width --;
	}
}

void	ft_left_indent(t_print *tab, int len)
{
	int	width;

	width = tab->width;
	while (width - len > 0)
	{
		tab->length += write(1, " ", 1);
		width --;
	}
}
