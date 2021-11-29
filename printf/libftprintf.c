/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:04:19 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 14:49:53 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft/libft.h"
#include "includes/libftprintf.h"

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
		if (s[i] == '%' && s[i + 1] == 'd')
		{
			i += 2;
		   	arg++;	
		}else
			i++;
	}	
	return arg;
}
int ft_printf(const char *s, ...)
{
	int	num_args;	
	va_list	args;
	int i;
	
	i = 0;
	num_args = calc_per(s);
	if (num_args == 0)
	{
		write (1, s, ft_strlen(s));
		return ft_strlen(s);
	}
	va_start(args, s);
	while ((num_args && s[i]) || s[i])
	{
		while ((s[i] != '%' && s[i + 1] != 'd') && s[i])
			ft_putchar_fd (s[i++], 1);
		if (!s[i])
			break;
		i+=2;
		if (num_args)
		{
			ft_putnbr_fd(va_arg(args, int), 1);	
			num_args--;
		}
	}
	va_end(args);
	return i;
}
int main()
{
	ft_printf("oussama%drahmouni\n",5,10);
	printf("***********\n");
	printf("oussama%drahmouni\n",5,10);
}
