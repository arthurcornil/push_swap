/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:41:10 by arcornil          #+#    #+#             */
/*   Updated: 2025/04/21 18:00:43 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_putuint(unsigned int num)
{
	int		factor;
	char	digit;

	factor = ft_get_factor(num);
	while (factor != 0)
	{
		digit = (num / factor) + '0';
		write(1, &digit, 1);
		num %= factor;
		factor /= 10;
	}
}

static int	ft_get_ndigits_u(unsigned int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num != 0)
	{
		num /= 10;
		i ++;
	}
	return (i);
}

static int	ft_format_indent(t_print *tab, int ndigits, int len, unsigned int n)
{
	if (tab->precision > ndigits)
	{
		len = tab->precision;
		if (n < 0)
			len ++;
	}
	if (tab->precision == 0 && n == 0)
		len --;
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, len);
	if (tab->precision > 0)
	{
		if (n < 0)
		{
			tab->sign = 1;
			n = -n;
			if (tab->precision > 0 && !tab->is_zero)
				ndigits --;
		}
		ft_format_precision(tab, ndigits);
	}
	tab->length += ndigits;
	return (len);
}

void	ft_print_uint(t_print *tab)
{
	unsigned int	num;
	int				ndigits;
	int				len;

	num = va_arg(tab->args, unsigned int);
	ndigits = ft_get_ndigits_u(num);
	len = ndigits;
	tab->is_num = true;
	if (tab->is_zero && (tab->width < 1 || tab->precision < 0))
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	else if (tab->is_zero && tab->width > 0 && tab->precision > -1)
		tab->is_zero = false;
	len = ft_format_indent(tab, ndigits, len, num);
	if (!(tab->precision == 0 && num == 0))
		ft_putuint(num);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, len);
	ft_reset_tab(tab);
}
