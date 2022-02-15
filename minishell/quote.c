/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:59:33 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/12 19:45:55 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*quotes(char *read_line)
{
	bool	open_quotes;
	char	quote;
	size_t	i;

	i = 0;
	quote = '\0';
	if (read_line == NULL || *read_line == '\0')
		return (NULL);
	open_quotes = false;
	while (1337)
	{
		/* if (read_line[i] == '\\') */
		/* { */
		/* 	if (read_line + i + 1) */
		/* 		read_line = ft_strjoin(ft_substr(read_line, 0, i), read_line + i + 1); */
		/* 	else */
		/* 		read_line = ft_substr(read_line, 0, i); */
		/* 	if (read_line[i + 1] == '\0' && open_quotes == false) */
		/* 		read_line = ft_strjoin(read_line, readline("> ")); */
		/* 	i = i + 2; */
		/* } */
		if (open_quotes == false && (read_line[i] == '\"' || read_line[i] == '\''))
		{
			if (quote == '\0')
			{
				quote = read_line[i];
				if (read_line + i + 1)
					read_line = ft_strjoin(ft_substr(read_line, 0, i), read_line + i + 1);
				else
					read_line = ft_substr(read_line, 0, i);
				open_quotes = true;
				i++;
			}
		}
		else if (open_quotes == true && (read_line[i] == '\"' || read_line[i] == '\''))
		{
			if (read_line[i] == quote)
			{
				if (read_line + i + 1)
					read_line = ft_strjoin(ft_substr(read_line, 0, i), read_line + i + 1);
				else
					read_line = ft_substr(read_line, 0, i);
				quote = '\0';
				open_quotes = false;
				i++;
			}
		}
		if (open_quotes == true && read_line[i] == '\0')
		{
			read_line = ft_strjoin(read_line, "\n");
			read_line = ft_strjoin(read_line, readline("dquote> "));
		}
		else if (open_quotes == false && read_line[i] == '\0')
			break ;
		i++;
	}
	return (read_line);
} 


int main()
{
	char	*parsed_data;
	
	parsed_data = readline("");
	parsed_data = quotes(parsed_data);
	printf ("%s\n", parsed_data);
}

/* char	*quotes(char *read_line, size_t *i) */
/* { */
/* 	static char	quote; */
/* 	static bool open = false; */
/* 	char		*tmp; */

/* 	if (read_line == NULL || (*read_line == '\0' && open == false)) */
/* 		return (NULL); */
/* 	while (read_line[*i]) */
/* 	{ */
/* 		while (read_line[*i] != '\"' && read_line[*i] != '\'' && read_line[*i] != '\0') */
/* 			(*i)++; */
/* 		if (read_line[*i] == '\0' && open == false) */
/* 		{ */
/* 			tmp = ft_strdup(read_line); */
/* 			free(read_line); */
/* 			return tmp; */
/* 		} */
/* 		else if (read_line[*i] == '\0' && open == true) */
/* 		{ */
/* 			tmp = ft_strjoin(read_line, readline("dquote> ")); */
/* 			return quotes(tmp, i); */
/* 		} */
/* 		else if (open == false) */
/* 		{ */
/* 			quote = read_line[*i]; */
/* 			open = true; */
/* 			return (ft_strdup(ft_substr(read_line, 0, *i))); */
/* 		} */
/* 		else if (open == true && quote == read_line[*i]) */
/* 		{ */
/* 			open = false; */
/* 			return (ft_strdup(ft_substr(read_line, 0, *i))); */
/* 		}else */
/* 			i++; */
/* 	} */
/* 	return (NULL); */
/* } */

/* int main() */
/* { */
/* 	char	*parsed_data; */
/* 	size_t		index; */

/* 	index = 0; */
/* 	parsed_data = ft_strdup("test \"hello\""); */
/* 	parsed_data = quotes(parsed_data, &index); */
/* 	printf ("%s -- %zu\n", parsed_data, index); */
/* 	parsed_data = quotes(parsed_data, &index); */
/* 	printf ("%s -- %zu\n", parsed_data, index); */
/* } */
/* char	*quotes(char *read_line) */
/* { */
/* 	/1* char	*new_line; *1/ */
/* 	bool	open; */
/* 	char	type; */
/* 	size_t	i; */

/* 	i = 0; */
/* 	open = false; */
/* 	while (1) */
/* 	{ */
/* 		while (read_line[i] != '\"' && read_line[i] != '\'' && read_line[i] != '\0') */
/* 			i++; */
/* 		if (read_line[i] == '\0' && open == false) */
/* 			return (read_line); */
/* 		if (read_line[i] != '\0') */
/* 			type = read_line[i++]; */
/* 		open = true; */
/* 		while (read_line[i] != type && read_line[i] != '\0') */
/* 			i++; */
/* 		if (read_line[i] == type && read_line[i + 1] == '\0') */
/* 			return (read_line); */
/* 		if (read_line[i] == type && read_line[i + 1] != '\0') */
/* 			open = false; */
/* 		if (read_line[i + 1] != '\"' && read_line[i + 1] != '\'') */
/* 		{ */
/* 			open = true; */
/* 			type = read_line[++i]; */
/* 			i++; */
/* 		} */
/* 		if (read_line[i] == '\0' && open == true) */
/* 			read_line = ft_strjoin (read_line, readline("dquote> ")); */
/* 		else */
/* 			i++; */
/* 	} */

/* 	return (NULL); */
/* } */

/* int main() */
/* { */
/* 	char *tmp = quotes("\"hello test\" \"oussama\"\""); */

/* 	printf ("%s\n", tmp); */
/* } */
