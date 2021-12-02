/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:33:32 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/02 18:19:34 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (ft_putstr_fd ("(null)", fd));
	}
	if (s != NULL)
	{
		while (s[i])
			i++;
		write (fd, s, i);
	}
	return (ft_strlen(s));
}
