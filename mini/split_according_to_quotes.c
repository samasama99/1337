/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/16 22:37:55 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	*trim_external_quotes(char *rl, int *i)
{
	char	*tmp;
	char	*tmp2;
	int		j;
	char	quote[2];

	if (rl == NULL || i == NULL)
		return (NULL);
	quote[0] = rl[*i];
	j = (*i)++;
	while (rl[*i] != quote[0])
		(*i)++;
	tmp2 = ft_substr(rl, j, *i - j + 1);
	tmp = ft_strtrim(tmp2, quote);
	free(tmp2);
	(*i)++;
	return (tmp);
}

char	*return_str_until_quote(char *rl, int *i)
{
	int		j;
	char	*tmp;

	if (rl == NULL || i == NULL)
		return (NULL);
	j = (*i)++;
	while (rl[*i] && rl[*i] != '\"' && rl[*i] != '\'')
		(*i)++;
	tmp = ft_substr(rl, j, *i - j);
	return (tmp);
}

char	**split_according_to_quotes(char *rl)
{
	char	**splited_rd;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (rl == NULL)
		return (NULL);
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
			splited_rd = split_and_join(splited_rd, tmp, ' ');
			free(tmp);
		}
		tmp = NULL;
	}
	return (splited_rd);
}

char	**spilt_with_sp_ignoring_external_quotes(char *str, char c)
{
	char	**splited_rd;
	char	quote;
	int		i;
	int		j;

	init_indexs(2, 0, &i, &j);
	if (str == NULL)
		return (NULL);
	splited_rd = init_2d_array();
	while (str[i])
	{
		if (skip_char(str, &i, c) == -1)
			break ;
		j = i;
		while (str[i] && str[i] != c)
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				quote = str[i++];
				skip_until_char(str, &i, quote);
			}
			i++;
		}
		splited_rd = add_element_2d_array_last(splited_rd,
				ft_substr(str, j, i - j));
	}
	return (splited_rd);
}

