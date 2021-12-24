/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:49:48 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/23 21:11:33 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdarg.h>

void		ft_printf(const char *s, ...);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_append_char(char *s, char c);
char		*ft_init_null(void);
#endif
