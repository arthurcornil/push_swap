/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcornil <arcornil@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:10 by arcornil          #+#    #+#             */
/*   Updated: 2025/05/03 12:28:48 by arcornil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	t_print	tab;
	int		i;

	ft_init_tab(&tab);
	va_start(tab.args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_get_format(&tab, format, i + 1);
		else
			tab.length += write(1, (format + i), 1);
		i ++;
	}
	va_end(tab.args);
	return (tab.length);
}
