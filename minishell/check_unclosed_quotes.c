/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unclosed_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:43:44 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/14 12:44:30 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	check_unclosed_quotes(char *read_line)
{
	bool	open_quotes;
	char	quote;

	quote = '\0';
	open_quotes = false;
	if (read_line == NULL || *read_line == '\0')
		return (1);
	while (*read_line)
	{
		if (*read_line == '\"' || *read_line == '\'')
		{
			if (open_quotes == false && quote == '\0')
			{
				quote = *read_line;
				open_quotes = true;
			}
			else if (*read_line == quote)
			{
				quote = '\0';
				open_quotes = false;
			}
		}
		++read_line;
	}
	return (open_quotes);
}
/* int main() */
/* { */
/* 	char	*rd; */
/* 	rd = readline("> "); */
/* 	if (check_unclosed_quotes(rd)) */
/* 		printf ("unclosed\n"); */
/* 	else */
/* 		printf ("closed\n"); */
/* } */
