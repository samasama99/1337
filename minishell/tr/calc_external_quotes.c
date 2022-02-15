/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_external_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:20:07 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/13 13:46:00 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"


/* size_t	calc_external_quotes(char *read_line) */
/* { */
/* 	bool	open_quotes; */
/* 	char	quote; */
/* 	size_t	calc; */
/* 	size_t	i; */

/* 	i = 0; */
/* 	quote = '\0'; */
/* 	calc = 0; */
/* 	open_quotes = false; */
/* 	if (read_line == NULL || *read_line == '\0') */
/* 		return (1); */
/* 	while (read_line[i]) */
/* 	{ */
/* 		if (read_line[i] == '\"' || read_line[i] == '\'') */
/* 		{ */
/* 			if (open_quotes == false && quote == '\0') */
/* 			{ */
/* 				quote = read_line[i]; */
/* 				open_quotes = true; */
/* 				if (i > 0 && read_line[i - 1] != ' ') */
/* 					calc++; */
/* 			} */
/* 			else if (read_line[i] == quote) */
/* 			{ */
/* 				quote = '\0'; */
/* 				open_quotes = false; */
/* 				calc++; */
/* 			} */
/* 		} */
/* 		++i; */
/* 	} */
/* 	return (calc); */
/* } */

static char	**free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free (tab[i++]);
	free (tab);
	return (0);
}

static	char	**allocat_tab(char const *s, char c, int *total)
{
	int		i;
	char	**tab;
	bool	open_quotes;
	char	quote;

	quote = '\0';
	open_quotes = false;

	i = 0;
	tab = NULL;
	while (s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			if (open_quotes == false && quote == '\0')
			{
				quote = s[i];
				open_quotes = true;
			}
			else if (s[i] == quote)
			{
				quote = '\0';
				open_quotes = false;
			}
		}
		if (open_quotes == false)
		{

			while (s[i] == c)
				i++;
			while (s[i] != c && s[i])
				i++;
			if (s[i - 1] != c)
				(*total)++;
		}
		else
			i++;
	}
	tab = (char **) malloc(sizeof(char *) * (*total + 1));
	if (!tab)
		return (0);
	tab[*total] = 0;
	return (tab);
}

static char	**allocate_string(char	**tab, char const *s, char c, int total)
{	
	int		i;
	int		t;
	int		start;

	if (!tab)
		return (0);
	t = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
		{
			tab[t] = ft_substr(s, start, i - start);
			if (tab[t] == 0)
				return (free_tab (tab, total));
			t++;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		total;

	if (s == NULL)
		return (0);
	total = 0;
	tab = allocat_tab (s, c, &total);
	tab = allocate_string (tab, s, c, total);
	return (tab);
}

/* int main() */
/* { */
/* 	char	*rd; */
/* 	rd = readline("> "); */
/* 	if (check_unclosed_quotes(rd)) */
/* 		printf ("unclosed\n"); */
/* 	else */
/* 		printf ("closed %zu\n", calc_external_quotes(rd)); */
/* } */

/* char	**split_according_to_quotes(char *read_line) */
/* { */
/* 	bool	open_quotes; */
/* 	char	quote; */

/* 	quote = '\0'; */
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
/* 			} */
/* 		} */
/* 		++read_line; */
/* 	} */
/* 	return (open_quotes); */
/* } */



int main()
{
	char	*rd;
	int i;

	
	rd = readline("> ");
	allocat_tab(rd, ' ', &i);
	if (check_unclosed_quotes(rd))
		printf ("unclosed\n");
	else
		printf ("closed %d\n", i);
}
