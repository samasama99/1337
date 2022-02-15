/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:48:05 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/13 17:42:18 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/* size_t	calc_external_quotes(char *read_line) */
/* { */
/* 	bool	open_quotes; */
/* 	char	quote; */
/* 	size_t	calc; */

/* 	quote = '\0'; */
/* 	calc = 0; */
/* 	open_quotes = false; */
/* 	if (read_line == NULL || *read_line == '\0') */
/* 		return (1); */
/* 	while (*read_line) */
/* 	{ */
/* 		if (*read_line == '\"' || *read_line == '\'') */
/* 		{ */
/* 			if (open_quotes == false && quote == '\0') */
/* 			{ */
/* 				quote = *read_line; */
/* 				open_quotes = true; */
/* 			} */
/* 			else if (*read_line == quote) */
/* 			{ */
/* 				quote = '\0'; */
/* 				open_quotes = false; */
/* 				calc++; */
/* 			} */
/* 		} */
/* 		++read_line; */
/* 	} */
/* 	return (calc); */
/* } */

char	*remove_str_in_str(char	*str, char *needle)
{
	size_t	i;
	char	*start;
	char	*end;
	char	*rest;

	i = 0;
	start = NULL;
	end = NULL;
	if (ft_strnstr(str, needle, ft_strlen(str)) == NULL)
			return (NULL);
	if (str != ft_strnstr(str, needle, ft_strlen(str)))
		start = ft_substr(str, 0 , ft_strnstr(str, needle, ft_strlen(str)) - str);
	if (ft_strnstr(str, needle, ft_strlen(str)) + ft_strlen(needle) + 1 != '\0')
		end = ft_strdup((ft_strnstr(str, needle, ft_strlen(str)) + ft_strlen(needle)));
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
		return end;
	return (NULL);
}

/* int main() */
/* { */
/* 	char *tmp; */

/* 	tmp = remove_str_in_str("hello test testhello", "hello"); */
/* 	printf("%s\n", tmp); */
/* 	while(true); */
/* } */


/* char	*remove_str_with_external_quotes(char *read_line, size_t amount) */
/* { */
/* 	bool	open_quotes; */
/* 	char	quote; */
/* 	size_t	i; */
/* 	size_t	start; */

/* 	i = 0; */
/* 	quote = '\0'; */
/* 	open_quotes = false; */
/* if (read_line == NULL || *read_line == '\0') *1/ */
/* 	return (1); */ 
	/* while (read_line[i]) */
	/* { */
	/* 	if (read_line[i] == '\"' || read_line[i] == '\'') */
	/* 	{ */
	/* 		if (open_quotes == false && quote == '\0') */
	/* 		{ */
	/* 			quote = read_line[i]; */
	/* 			open_quotes = true; */
	/* 			start = i; */
	/* 		} */
	/* 		else if (read_line[i] == quote) */
	/* 		{ */
	/* 			quote = '\0'; */
	/* 			open_quotes = false; */
	/* 		} */
	/* 	} */
	/* 	++i; */
	/* } */
/* 	return (0); */
/* } */


