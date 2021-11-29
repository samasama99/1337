/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:04:19 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 22:42:18 by orahmoun         ###   ########.fr       */
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

int	calc_per(const char *s)
{
	int	i;
	int	arg;

	i = 0;
	arg = 0;
	if (!s || !ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (s[i] == '%' && ft_charexist(s[i + 1], "xXsdcipu"))
		{
			i += 2;
		   	arg++;	
		}else
			i++;
	}	
	return arg;
}

int print_type (char type, va_list arg)
{
	int len;
	if (type == 'd' || type == 'i')
		len = ft_putnbr_fd(va_arg(arg, int), 1);	
	else if (type == 'u')
		len = ft_putnbr_u_fd((unsigned int)va_arg(arg, unsigned int), 1);
	else if (type == 's')
		len = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (type == 'c')
		len = ft_putchar_fd(va_arg(arg, int), 1);
	else if (type == 'x')
		len = ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
	else if (type == 'X')
		len = ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
	else if (type == 'p')
	{
		ft_putstr_fd("0x", 1);
		len = ft_putnbr_base_ul(va_arg(arg, unsigned long), "0123456789abcdef") + 2;
	}
	return len;
}

int ft_printf(const char *s, ...)
{
	int		num_args;	
	va_list	args;
	char	type;
	int		i;
	int		len;

	i = 0;
	rd = 0;
	num_args = calc_per(s);
	num_args_cpy = calc_per(s);
	if (num_args == 0)
	{
		write (1, s, ft_strlen(s));
		return ft_strlen(s);
	}
	va_start(args, s);
	while (s[i])
	{
		while (s[i])
		{
			if (s[i] == '%' && ft_charexist(s[i + 1], "xXdscipu"))
				break;
			ft_putchar_fd (s[i++], 1);
		}
		if (!s[i])
			break;
		type = s[i + 1];
		i+=2;
		if (num_args)
		{
			print_type (type, args);
			num_args--;
			rd++;
		}
	}
	va_end(args);
	return ft_strlen(s);
}
/*
int main()
{
	int a = 10;
	ft_printf("%c %d %d %i %u %d %s %x %X %p\n", 'A' , 'A' , 5 , -10 , -10 , 10 , "HELLO", 255 , 255 , &a);
	printf("***********\n");
	printf   ("%c %d %d %i %u %d %s %x %X %p\n", 'A' , 'A' , 5 , -10 , -10 , 10 , "HELLO", 255 , 255 , &a);
}*/
