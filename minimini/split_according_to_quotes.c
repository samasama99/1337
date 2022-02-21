/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/18 21:51:51 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	*return_quoted_arg(char *rl, int *i)
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
	/* free(tmp2); */
	(*i)++;
	return (tmp);
}

char	*return_unquoted_arg(char *rl, int *i)
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

char	**return_args_after_removing_quotes(char *rl)
{
	char	**splited_rd;
	char	*tmp;
	/* char	*tmp2; */
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
			j = i;
			tmp = return_quoted_arg(rl, &i);
			if (rl[j] == '\"')
			{
				tmp = replace_variable_with_value(ENV, tmp);
				/* free(tmp); */
				/* tmp = tmp2; */
				/* tmp2 = NULL; */
			}
			splited_rd = add_element_2d_array_last(splited_rd, tmp);
		}
		else
		{
			tmp = return_unquoted_arg(rl, &i);
			tmp = replace_variable_with_value(ENV, tmp);
			splited_rd = split_and_join(splited_rd, tmp, ' ');
			/* free(tmp); */
		}
		tmp = NULL;
	}
	return (splited_rd);
}
