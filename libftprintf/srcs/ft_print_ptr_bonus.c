/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:59:48 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/03 12:57:34 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	ft_ptr_to_hex(unsigned long num, char *base)
{
	unsigned long	lengthbase;

	lengthbase = 16;
	if (num >= lengthbase)
	{
		ft_ptr_to_hex(num / lengthbase, base);
		num %= lengthbase;
	}
	ft_putchar_fd(*(base + num), 1);
}

static unsigned int	ft_get_ndigits_ptr_to_hex(unsigned long ptr)
{
	int	ndigits;

	ndigits = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		ndigits ++;
	}
	return (ndigits);
}

void	ft_print_ptr(t_print *tab)
{
	unsigned long	ptr;
	int				ndigits_hex;

	ptr = va_arg(tab->args, unsigned long);
	ndigits_hex = ft_get_ndigits_ptr_to_hex(ptr);
	ndigits_hex += 2;
	if (tab->precision == 0 && ptr == 0)
		ndigits_hex --;
	if (tab->width > 0 && !tab->dash)
		ft_right_indent(tab, ndigits_hex);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		ndigits_hex = 5;
	}
	else if (tab->precision != 0 && ptr != 0)
	{
		write(1, "0x", 2);
		ft_ptr_to_hex(ptr, "0123456789abcdef");
	}
	tab->length += ndigits_hex;
	if (tab->width > 0 && tab->dash)
		ft_left_indent(tab, ndigits_hex);
	ft_reset_tab(tab);
}
