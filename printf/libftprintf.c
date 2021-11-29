/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:04:19 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 19:38:23 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft/libft.h"
#include "includes/libftprintf.h"

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
		if (s[i] == '%' && ft_charexist(s[i + 1], "xXsdcip"))
		{
			i += 2;
		   	arg++;	
		}else
			i++;
	}	
	return arg;
}

void print_type (char type, va_list arg)
{
	if (type == 'd' || type == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);	
	else if (type == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
	else if (type == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (type == 'x')
		ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
	else if (type == 'X' || type == 'p')
		ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
	else if (type == 'p')
		ft_putnbr_base_ul(va_arg(arg, unsigned long), "0123456789ABCDEF");
}

int ft_printf(const char *s, ...)
{
	int		num_args;	
	va_list	args;
	char	type;
	int		i;
	
	i = 0;
	num_args = calc_per(s);
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
			if (s[i] == '%' && ft_charexist(s[i + 1], "xXdscip"))
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
		}
	}
	va_end(args);
	return i;
}
int main()
{
	int a = 10;
	ft_printf("%c %d %i %d %s %x %X %p\n", 'A' , 'A' , 5 , 10 , "HELLO", 255 , 255 , &a);
	printf("***********\n");
	printf("%c %d %i %d %s %x %X %p\n", 'A' , 'A' , 5 , 10 , "HELLO", 255 , 255 , &a);
}
