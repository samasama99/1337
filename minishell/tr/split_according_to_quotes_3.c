/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/14 16:37:06 by orahmoun         ###   ########.fr       */
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

char	**split_according_to_quotes(char *rl)
{
	char	**splited_rd;
	char	*tmp;
	int		i;
	int		j;
	char	quote[2];

	init_indexs(2, 0, &i, &j);
	splited_rd = init_2d_array();
	quote[1] = '\0';
	while (rl[i])
	{
		if (rl[i] == '\"' || rl[i] == '\'')
		{
			*quote = rl[i];
			j = i++;
			while (rl[i] != *quote)
				i++;
			tmp = ft_substr(rl, j, i - j + 1);
			tmp = ft_strtrim(tmp, quote);
			if (j > 0 && rl[j - 1] != ' ')
			{
				tmp = ft_strjoin(splited_rd[size_of_2d_array(splited_rd) - 1], tmp);
				splited_rd = delete_element_2d_array(splited_rd, size_of_2d_array(splited_rd) - 1);
			}
			splited_rd = add_element_2d_array_last(splited_rd, tmp);
			i++;
		}
		else
		{
			j = i++;
			while (rl[i] && rl[i] != '\"' && rl[i] != '\'')
				i++;
			tmp = ft_substr(rl, j, i - j);
			if (j > 0 && rl[j - 1] != ' ')
			{
				tmp = ft_strjoin(splited_rd[size_of_2d_array(splited_rd) - 1], tmp);
				splited_rd = delete_element_2d_array(splited_rd, size_of_2d_array(splited_rd) - 1);
			}
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
			}
			else
				printf ("unclosed quotes\n");
			if (pipes[i + 1])
				printf ("---\n");
			i++;
			free_2d_array(init);
			init = NULL;
		}
		free_2d_array(pipes);
		free_2d_array(init);
		pipes = NULL;
		init = NULL;
		i = 0;
	}
}
