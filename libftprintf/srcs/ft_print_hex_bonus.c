/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:45 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/03 12:59:30 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_print_num(unsigned int num, char *base)
{
	int	lengthbase;

	lengthbase = 16;
	if (num >= (unsigned int)lengthbase)
	{
		ft_print_num(num / lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

static int	ft_get_ndigits_hex(unsigned int num)
{
	int	ndigits;

	ndigits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		ndigits ++;
	}
	return (ndigits);
}

static int	ft_format_indent(t_print *tab, int ndigit, unsigned int n)
{
	int	len;

	len = ndigit;
	if (tab->precision > ndigit)
		len = tab->precision;
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
				ndigit --;
		}
		ft_format_precision(tab, ndigit);
	}
	tab->length += ndigit;
	return (len);
}

static void	ft_print_hex_with_base(t_print *tab, char *base, char *suffix)
{
	unsigned int	num;
	int				ndigits;
	int				len;

	num = va_arg(tab->args, unsigned int);
	ndigits = ft_get_ndigits_hex(num);
	if (tab->hashtag && num != 0)
		ndigits += 2;
	tab->is_num = true;
	if (tab->is_zero && (tab->width < 1 || tab->precision < 0))
	{
		tab->precision = tab->width;
		tab->width = 0;
	}
	else if (tab->is_zero && tab->width > 0 && tab->precision > -1)
		tab->is_zero = false;
	len = ft_format_indent(tab, ndigits, num);
	if (tab->hashtag && num != 0)
		write(1, suffix, 2);
	if (!(tab->precision == 0 && num == 0))
		ft_print_num(num, base);
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, len);
	ft_reset_tab(tab);
}

void	ft_print_hex(t_print *tab, bool uppercase)
{
	if (uppercase)
	{
		ft_print_hex_with_base(tab, "0123456789ABCDEF", "0X");
		return ;
	}
	ft_print_hex_with_base(tab, "0123456789abcdef", "0x");
}
