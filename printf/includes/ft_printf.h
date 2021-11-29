/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:56:55 by orahmoun          #+#    #+#             */
/*   Updated: 2021/11/29 21:37:25 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int		ft_printf(const char *, ...);
void    ft_putchar_fd(char c, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_putnbr_u_fd(unsigned int n, int fd);
void    ft_putnbr_base(int nbr, char *base);
void    ft_putnbr_base_ul(unsigned long nbr, char *base);
void    ft_putstr_fd(char *s, int fd);
void    ft_putchar_fd(char c, int fd);
size_t  ft_strlen(const char *s);
#endif
