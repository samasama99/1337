/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:48:25 by orahmoun          #+#    #+#             */
/*   Updated: 2021/12/23 16:51:27 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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
