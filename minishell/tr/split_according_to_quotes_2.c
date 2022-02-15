/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/14 16:37:01 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* char	**split_according_to_quotes(char *rl) */
/* { */
/* 	char	**splited_rd; */

/* 	splited_rd = ft_split(rl, ' '); */
/* 	return (splited_rd); */
/* } */

/* char	*return_next_element(char *rd) */
/* { */
/* 	static size_t	i; */
/* 	size_t			old_i; */
/* 	bool			open; */
/* 	char			quote; */

/* 	quote = '\0'; */
/* 	old_i = i; */
/* 	open = false; */
/* 	if (rd == NULL || rd[i] == '\0') */
/* 		return (NULL); */
/* 	while (rd[i]) */
/* 	{ */
/* 		if (rd[i] == '\'' || rd[i] == '\"') */
/* 		{ */
/* 			if (open == false) */
/* 			{ */
/* 				quote = rd[i]; */
/* 				open = true; */
/* 				if (i - old_i > 0) */
/* 					return (ft_substr(rd, old_i , ++i - 1)); */
/* 			} */
/* 			else if (open == true && quote == rd[i]) */
/* 			{ */
/* 				quote = '\0'; */
/* 				open = false; */
/* 				return ft_substr(rd, old_i, ++i); */
/* 			} */
/* 		} */
/* 		i++; */
/* 	} */
/* 	if (rd[old_i]) */
/* 		return (ft_strdup(rd + old_i + 1)); */
/* 	return (NULL); */
/* } */

char	*return_next_element(char *rd)
{
	static size_t	i;
	size_t			old_i;
	static bool		open;
	static char		quote;

	quote = '\0';
	old_i = i;
	open = false;
	if (rd == NULL || rd[i] == '\0')
		return (NULL);
	if (open == true || rd[i] == quote)
	{
		open = false;
		old_i = i;
		i = i + ft_strchr(rd + i + 1, rd[i]) - rd + i;
		return (ft_substr(rd + old_i, 0, ft_strchr(rd + old_i + 1, rd[i]) - rd + old_i + 1));
	}
	while (rd[i])
	{
		if (rd[i] == '\'' || rd[i] == '\"')
		{
			if (open == false)
			{
				quote = rd[i];
				open = true;
				if (i - old_i > 0)
					return (ft_substr(rd, old_i , i - 1));
			}
		}
		i++;
	}
	if (rd[old_i])
		return (ft_strdup(rd + old_i));
	return (NULL);
}
int main()
{
	char *rd = readline("> ");

	printf ("%s\n", return_next_element(rd));
	printf ("%s\n", return_next_element(rd));
	printf ("%s\n", return_next_element(rd));
	printf ("%s\n", return_next_element(rd));
}
