/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:12:52 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 22:15:51 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, len)
{
	long int	nb;
	static int	len;
	
	nb = nbr;
	nb++;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb / 16 != 0)
		ft_putnbr_base (nb / 16, base);
	write(1, &base[nb % 16], 1);
	return nb;
}
void	ft_putnbr_base_ul(unsigned long nbr, char *base)
{
	unsigned long 	nb;
	static int	len;
	len++;
	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base_ul (nb / 16, base);
	write(1, &base[nb % 16], 1);
	return len;
}
