/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:21:47 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/08 10:17:29 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_stack (t_stack s)
{
	int	i;

	i = 0;
	write (1, s.name, 1);
	write (1, " :\n", 3);
	while (i < s.n_elements)
	{
		ft_putnbr_fd (s.elements[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}

/* static void	print_two_stack (t_stack a, t_stack b) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	write (1, a.name, 1); */
/* 	write (1, " :  ", 4); */
/* 	write (1, b.name, 1); */
/* 	write (1, " :\n", 3); */
/* 	while (a.n_elements || b.n_elements) */
/* 	{ */
/* 		if (a.n_elements) */
/* 		{ */
/* 			ft_putnbr_fd (a.elements[i], 1); */
/* 			a.n_elements--; */
/* 		} */
/* 		else */
/* 			write (1, " ", 1); */
/* 		if (b.n_elements) */
/* 		{ */
/* 			write (1, "    ", 4); */
/* 			ft_putnbr_fd (b.elements[i], 1); */
/* 			b.n_elements--; */
/* 		} */
/* 		i++; */
/* 		ft_putchar_fd('\n', 1); */
/* 	} */
/* } */
