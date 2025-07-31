/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:50:34 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/11 15:36:52 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	ft_get_value(t_print *tab, const char *str, int pos)
{
	while (ft_isdigit(str[pos]))
	{
		if (tab->precision == -1)
			tab->width = tab->width * 10 + str[pos] - '0';
		else if (tab->precision > -1 || tab->is_zero)
			tab->precision = tab->precision * 10 + str[pos] - '0';
		if (!ft_isdigit(str[pos + 1]))
			break ;
		pos ++;
	}
	return (pos);
}

static int	ft_parse_flags(t_print *tab, const char *str, int pos)
{
	while (!(str[pos] == 'c' || str[pos] == 's' || str[pos] == 'p'
			|| str[pos] == 'd' || str[pos] == 'i' || str[pos] == 'u'
			|| str[pos] == 'x' || str[pos] == 'X' || str[pos] == '%'))
	{
		if (str[pos] == '.')
			tab->precision = 0;
		else if (str[pos] == '-')
			tab->dash = 1;
		else if (str[pos] == '+')
			tab->sign = 1;
		else if (str[pos] == '0' && !ft_isdigit(str[pos - 1])
			&& tab->precision == -1)
			tab->is_zero = 1;
		else if (str[pos] == ' ')
			tab->space = 1;
		else if (str[pos] == '#')
			tab->hashtag = 1;
		pos = ft_get_value(tab, str, pos);
		pos ++;
	}
	return (pos);
}

int	ft_get_format(t_print *tab, const char *str, int pos)
{
	pos = ft_parse_flags(tab, str, pos);
	if (tab->is_zero && tab->width == 0)
		tab->is_zero = 0;
	if (str[pos] == 'c')
		ft_print_char(tab);
	else if (str[pos] == 'd' || str[pos] == 'i')
		ft_print_int(tab);
	else if (str[pos] == 's')
		ft_print_str(tab);
	else if (str[pos] == 'u')
		ft_print_uint(tab);
	else if (str[pos] == '%')
		ft_print_percent(tab);
	else if (str[pos] == 'x')
		ft_print_hex(tab, false);
	else if (str[pos] == 'X')
		ft_print_hex(tab, true);
	else if (str[pos] == 'p')
		ft_print_ptr(tab);
	return (pos);
}
