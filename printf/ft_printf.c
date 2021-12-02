/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:04:19 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/02 18:25:28 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "includes/ft_printf.h"

static int	ft_charexist(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	print_type(char type, va_list arg)
{
	char	*hex_l;
	char	*hex_u;

	hex_l = "0123456789abcdef";
	hex_u = "0123456789ABCDEF";
	if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (type == 'u')
		return (ft_putnbr_u_fd ((unsigned int)va_arg(arg, unsigned int), 1));
	else if (type == 's')
		return (ft_putstr_fd (va_arg(arg, char *), 1));
	else if (type == 'c')
		return (ft_putchar_fd (va_arg(arg, int), 1));
	else if (type == 'x')
		return (ft_putnbr_base (va_arg(arg, int), hex_l));
	else if (type == 'X')
		return (ft_putnbr_base (va_arg(arg, int), hex_u));
	else if (type == 'p')
	{
		ft_putstr_fd ("0x", 1);
		return (ft_putnbr_base_long(va_arg(arg, unsigned long), hex_l) + 2);
	}
	else if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start (args, s);
	while (s[i])
	{
		while (s[i])
		{
			if (s[i] == '%' && ft_charexist (s[i + 1], "xXdscipu%"))
				break ;
			else if (s[i] == '%')
				i++;
			len += ft_putchar_fd (s[i++], 1);
		}
		if (s[i])
		{
			len += print_type (s[i + 1], args);
			i += 2;
		}
	}
	va_end (args);
	return (len);
}
