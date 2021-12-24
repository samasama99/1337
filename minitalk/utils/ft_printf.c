/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:20:06 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/23 16:51:30 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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

static void	print_type(char type, va_list arg)
{
	if (type == 'd')
		(ft_putnbr_fd(va_arg(arg, int), 1));
	else if (type == 's')
		(ft_putstr_fd (va_arg(arg, char *), 1));
	else if (type == 'c')
		(ft_putchar_fd (va_arg(arg, int), 1));
}

void	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start (args, s);
	while (s[i])
	{
		while (s[i])
		{
			if (s[i] == '%' && ft_charexist (s[i + 1], "dsc"))
				break ;
			else if (s[i] == '%')
				i++;
			ft_putchar_fd (s[i++], 1);
		}
		if (s[i])
		{
			print_type (s[i + 1], args);
			i += 2;
		}
	}
	va_end (args);
}
