/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:10:21 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 19:37:08 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <stdarg.h>
int		ft_printf(const char *, ...);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr_base_ul(unsigned long nbr, char *base);
#endif
