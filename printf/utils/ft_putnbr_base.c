/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:12:52 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 19:38:58 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_char_repeat(char *str1, char *str2)
{
	if (*str1 == *str2)
		return (0);
	if (*str2)
		return (ft_char_repeat(str1, ++str2));
	if (*(str1 + 1) == 0)
		return (1);
	str1++;
	str2 = str1 + 1;
	return (ft_char_repeat(str1, str2));
}

int	ft_check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] && ft_char_repeat(base, base + 1))
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			b;
	long int	nb;

	nb = nbr;
	b = ft_check_base(base);
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (b > 1)
	{
		if (nb / b != 0)
			ft_putnbr_base (nb / b, base);
		write(1, &base[nb % b], 1);
	}
}

void	ft_putnbr_base_ul(unsigned long nbr, char *base)
{
	unsigned long 	b;
	unsigned long 	nb;

	nb = nbr;
	b = ft_check_base(base);
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (b > 1)
	{
		if (nb / b != 0)
			ft_putnbr_base (nb / b, base);
		write(1, &base[nb % b], 1);
	}
}
