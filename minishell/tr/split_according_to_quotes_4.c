/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/14 17:27:30 by orahmoun         ###   ########.fr       */
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
	splited_rd = init_2d_array();
	while (rl[i])
	{
		if (rl[i] == '\"' || rl[i] == '\'')
		{
			j = i;
			tmp = trim_external_quotes(rl, &i);
			while (j > 0 && rl[j - 1] != ' ' && (rl[i] == '\"' || rl[i] == '\'') && rl[i])
			{
				j = i;
				tmp = ft_strjoin(tmp, trim_external_quotes(rl, &i));
			}
			while (j > 0 && rl[j - 1] != ' ' && rl[i])
			{
				j = i;
				tmp = ft_strjoin(tmp, return_str_until_quote(rl, &i));
			}
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

int main()
{
	char		*rd;
	char		**init;
	char		**pipes;
	int			i;

	i = 0;
	while (1)
	{
		rd = readline("> ");
		add_history(rd);
		pipes = ft_split(rd, '|');
		while(pipes[i])
		{
			if (check_unclosed_quotes(pipes[i]) == false)
			{
				init = split_according_to_quotes(pipes[i]);
				print_2d_array(init, 1);
				free_2d_array(init);
				init = NULL;
			}
			else
			{
				printf ("unclosed quotes\n");
				continue ;
			}
			if (pipes[i + 1])
				printf ("---\n");
			i++;
		}
		free_2d_array(pipes);
		pipes = NULL;
		i = 0;
	}
}
