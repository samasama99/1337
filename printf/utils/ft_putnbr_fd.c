/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:52:29 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/01 19:36:05 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int decimal_len(int num)
{
	int	len;

	if (num < 0)
		len++;
	len = 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return len;
}

int decimal_len_u(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num = num / 10;
		len++;
	}
	return len;
}

int	ft_putnbr_fd(int nb, int fd)
{
	int n;
   	n = nb;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ft_strlen("-2147483648");
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	return decimal_len(nb);
}

int	ft_putnbr_u_fd(unsigned int nb, int fd)
{
	unsigned int	n; 

	n = nb;
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
	return decimal_len_u(nb);
}
#include <stdio.h>
int main()
{
	ft_putnbr_fd(100, 1);
	write(1,"\n",1);
	ft_putnbr_fd(-100, 1);
	write(1,"\n",1);
	ft_putnbr_u_fd(100, 1);
	write(1,"\n",1);
	ft_putnbr_u_fd(-100, 1);
	write(1,"\n",1);
	printf("%u", -100);
}
