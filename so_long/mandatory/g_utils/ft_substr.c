/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 12:54:46 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/03 17:16:25 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((long int)len < 0 || !s)
		return (NULL);
	if (len > (size_t)ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc (sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
