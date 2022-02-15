/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/15 10:30:20 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	**split_and_join(char **array, char *line)
{
	char	**splited;

	if (line == NULL || *line == '\0')
		return (array);
	splited = ft_split(line, ' ');
	array = join_2d_array(array, splited);
	return (array);
}

char	*trim_external_quotes(char *rl, int *i)
{
	char	*tmp;
	int		j;
	char	quote[2];

	if (rl[*i] && rl[*i] != '\"' && rl[*i] != '\'' && rl[*i] != ' ')
		return (NULL);
	quote[0] = rl[*i];
	j = (*i)++;
	while (rl[*i] != quote[0])
		(*i)++;
	tmp = ft_substr(rl, j, *i - j + 1);
	tmp = ft_strtrim(tmp, quote);
	(*i)++;
	return (tmp);
}

char	*return_str_until_quote(char *rl, int *i)
{
	int		j;
	char	*tmp;

	j = (*i)++;
	while (rl[*i] && rl[*i] != '\"' && rl[*i] != '\'')
		(*i)++;
	tmp = ft_substr(rl, j, *i - j);
	return tmp;
}

char	**split_according_to_quotes(char *rl)
{
	char	**splited_rd;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	splited_rd = init_2d_array();
	while (rl[i])
	{
		if (rl[i] == '\"' || rl[i] == '\'')
		{
			tmp = trim_external_quotes(rl, &i);
			splited_rd = add_element_2d_array_last(splited_rd, tmp);
		}
		else
		{
			tmp = return_str_until_quote(rl, &i);
			splited_rd = split_and_join(splited_rd, tmp);
		}
	}
	return (splited_rd);
}

char	*join_2d_array_into_str(char **array)
{
	char	*joined;
	size_t	i;

	i = 0;
	if (array == NULL)
		return (NULL);
	joined = ft_strdup("");
	while (array[i])
		joined = ft_strjoin(joined, array[i++]);
	if (joined == NULL || *joined == '\0')
		return (NULL);
	return (joined);
}

char	**spilt_with_sp_ignoring_external_quotes(char *str)
{
	char	**splited_rd;
	char	*tmp;
	char	quote;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	tmp = NULL;
	splited_rd = init_2d_array();
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break ;
		j = i;
		while (str[i] && str[i] != ' ')
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				quote = str[i];
				i++;
				while (str[i] && str[i] != quote)
					i++;
				printf ("%zu %zu\n", j, i);
			}
			tmp = ft_substr(str, j, i - j);
		}
		splited_rd = split_and_join(splited_rd, tmp);
	}
	return (splited_rd);
}

int main()
{
	char		*rd;
	char		**sp;
	char		**parsed;
	int			i;

	i = 0;
	parsed = init_2d_array();
	while (1)
	{
		rd = readline("> ");
		add_history(rd);
		sp = spilt_with_sp_ignoring_external_quotes(rd);
		print_2d_array(sp, 1);
		/* while (sp[i]) */
		/* { */
		/* 	parsed = add_element_2d_array_last(parsed, join_2d_array_into_str(split_according_to_quotes(sp[i]))); */
		/* 	i++; */
		/* } */
		/* print_2d_array(parsed, 1); */
		free_2d_array(sp);
		sp = NULL;
		/* free_2d_array(parsed); */
		/* parsed = init_2d_array(); */
		/* i = 0; */
	}
}
