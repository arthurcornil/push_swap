/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:40:11 by arcornil          #+#    #+#             */
/*   Updated: 2025/03/17 13:23:46 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_print_percent(t_print *tab)
{
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, 1);
	tab->length += write(1, "%", 1);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, 1);
	ft_reset_tab(tab);
}
