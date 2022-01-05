/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:55:23 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/03 22:48:37 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;
	int		l;

	l = 0;
	i = 0;
	while (s[l])
		l++;
	temp = (char *)malloc(l + 1);
	if (!temp)
		return (0);
	while (i < l)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
