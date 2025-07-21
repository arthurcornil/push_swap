/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:04:14 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/11 15:47:14 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_manage_flags(t_print *tab, int num)
{
	if (tab->precision < 0 && tab->sign == 1 && num >= 0)
		tab->length += write(1, "+", 1);
	else if (tab->precision < 0 && tab->space && num >= 0)
		tab->length += write(1, " ", 1);
}

static void	ft_manage_zero(t_print *tab)
{
	if (tab->is_zero && ((tab->width < 1) != (tab->precision < 0)))
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	else if (tab->is_zero && tab->width > 0 && tab->precision > -1)
		tab->is_zero = false;
}

static int	ft_format_indent(t_print *tab, int ndigits, int len, long int *num)
{
	if (tab->precision >= ndigits)
	{
		len = tab->precision;
		if (*num < 0)
			len ++;
	}
	if (tab->precision == 0 && *num == 0)
		len --;
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, len);
	if (tab->precision > 0 || tab->width > 0)
	{
		if (*num < 0)
		{
			tab->sign = 2;
			*num = -(*num);
			if (!tab->is_zero && len > ndigits)
				ndigits --;
		}
		ft_format_precision(tab, ndigits);
	}
	tab->length += ndigits;
	return (len);
}

void	ft_print_int(t_print *tab)
{
	long int	num;
	int			ndigits;
	int			len;

	num = (long int)va_arg(tab->args, int);
	ndigits = ft_get_ndigits((int)num);
	len = ndigits;
	tab->is_num = true;
	ft_manage_zero(tab);
	len = ft_format_indent(tab, ndigits, len, &num);
	ft_manage_flags(tab, num);
	if (!(tab->precision == 0 && num == 0))
		ft_putnbr_fd(num, 1);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, len);
	ft_reset_tab(tab);
}
