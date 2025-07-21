/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:02:53 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/22 10:03:25 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, 1);
	tab->length += write(1, &a, 1);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, 1);
	ft_reset_tab(tab);
}
