/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:12:52 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/02 18:19:23 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	hex_len(unsigned int x)
{
	int	len;

	len = 0;
	if (!x)
		return (1);
	while (x)
	{
		x = x / 16;
		len++;
	}
	return (len);
}

static int	hex_len_long(unsigned long x)
{
	int	len;

	len = 0;
	if (!x)
		return (1);
	while (x)
	{
		x = x / 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	nb;

	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base (nb / 16, base);
	write(1, &base[nb % 16], 1);
	return (hex_len(nbr));
}

int	ft_putnbr_base_long(unsigned long nbr, char *base)
{
	unsigned long	nb;

	nb = nbr;
	if (nb / 16 != 0)
		ft_putnbr_base_long (nb / 16, base);
	write(1, &base[nb % 16], 1);
	return (hex_len_long(nbr));
}
