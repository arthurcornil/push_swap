/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:40:54 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/11 15:38:51 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	if (tab->precision == 0)
		str = "";
	len = ft_strlen(str);
	if (tab->precision > 0 && tab->precision < len)
		len = tab->precision;
	tab->length += len;
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, len);
	i = 0;
	while (i < len)
	{
		ft_putchar_fd(str[i], 1);
		i ++;
	}
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, len);
	ft_reset_tab(tab);
}
