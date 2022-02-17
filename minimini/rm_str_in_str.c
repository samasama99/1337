/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_str_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:43:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/13 17:54:03 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	*remove_str_in_str(char	*s, char *n)
{
	char	*start;
	char	*end;
	char	*rest;

	start = NULL;
	end = NULL;
	if (ft_strnstr(s, n, ft_strlen(s)) == NULL)
		return (NULL);
	if (s != ft_strnstr(s, n, ft_strlen(s)))
		start = ft_substr(s, 0, ft_strnstr(s, n, ft_strlen(s)) - s);
	if (ft_strnstr(s, n, ft_strlen(s)) + ft_strlen(n) + 1 != '\0')
		end = ft_strdup((ft_strnstr(s, n, ft_strlen(s)) + ft_strlen(n)));
	if (start && end && *start && *end)
	{
		rest = ft_strjoin(start, end);
		free(start);
		free(end);
		return (rest);
	}
	else if (start && *start)
		return (start);
	else if (end && *end)
		return (end);
	return (NULL);
}
