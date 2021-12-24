/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:26:21 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/23 16:51:33 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

char	*ft_append_char(char *s, char c)
{
	char	*str;
	int		i;

	if (s == 0)
		s = ft_init_null();
	str = (char *)malloc (ft_strlen(s) + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	free(s);
	s = NULL;
	return (str);
}
