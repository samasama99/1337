/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_str_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:43:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/17 17:45:48 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	*str_replace(char	*s, char *f, char *r)
{
	char	*start;
	char	*end;
	char	*rest;

	start = NULL;
	end = NULL;
	if (!s || !f || !r || *f == 0|| *r == 0)
		return (NULL);
	if (ft_strncmp(s, f, ft_strlen(f)) == 0 && ft_strlen(f) == ft_strlen(s))
		return (ft_strdup(r));
	if (ft_strnstr(s, f, ft_strlen(s)) == NULL)
		return (NULL);
	if (s != ft_strnstr(s, f, ft_strlen(s)))
		start = ft_substr(s, 0, ft_strnstr(s, f, ft_strlen(s)) - s);
	if (ft_strnstr(s, f, ft_strlen(s)) + ft_strlen(f) + 1 != '\0')
		end = ft_strdup((ft_strnstr(s, f, ft_strlen(s)) + ft_strlen(f)));
	if (start && end && *start && *end)
	{
		rest = ft_strjoin(start, r);
		rest = ft_strjoin(rest, end);
		free(start);
		free(end);
		return (rest);
	}
	else if (start && *start)
		return ft_strjoin(start, rest);
	else if (end && *end)
		return (ft_strjoin(rest, end));
	return (NULL);
}


/* int main() */
/* { */
/* 	char *test = "oussama$PATHrahmouni"; */
/* 	test = str_replace(test, "oussama", "path/path"); */
/* 	printf ("%s\n", test); */
/* } */
