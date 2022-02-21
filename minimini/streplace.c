/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_str_in_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:43:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/18 21:48:24 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* char	*str_replace(char	*s, char *f, char *r) */
/* { */
/* 	char	*newstr; */
/* 	int		i; */

/* 	i = 0; */
/* 	if (!s && !f && !r) */
/* 		return (NULL); */
/* 	if (ft_strnstr(s, f, ft_strlen(s)) == NULL) */
/* 		return (ft_strdup(s)); */
/* 	newstr = malloc (ft_strlen(s) - ft_strlen(f) + ft_strlen(r)); */
/* 	while (s + i != ft_strnstr(s, f, ft_strlen(s))) */
/* 		i++; */
/* 	ft_strlcpy(newstr, s, i + 2); */
/* 	ft_strlcpy(newstr + ft_strlen(newstr) - 1, r, ft_strlen(r) + 1); */
/* 	ft_strlcpy(newstr + ft_strlen(newstr), s + i + ft_strlen(f), */
/* 		ft_strlen(s) - ft_strlen(f) - i + 1); */
/* 	return (newstr); */
/* } */

/* int main() */
/* { */
/* 	char *test = "$PATHoussama"; */
/* 	test = streplace(test, "$PATH", "path/path"); */
/* 	printf ("%s\n", test); */
/* } */
