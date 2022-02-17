/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_according_to_quotes_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:01:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/17 17:56:17 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	*replace_variable_with_value(char **env, char *str)
{
	size_t	i;
	size_t	j;
	int		index;
	char	*variable;
	char	*new_str;

	i = 0;
	j = 0;
	if (str == NULL || ft_strchr(str, '$') == NULL)
		return (str);
	new_str = ft_strdup(str);
	while (str[i])
	{
		if (str[i] == '$')
		{
			j = i++;
			while (str[i] && str[i] != '$' && str[i] != ' ')
				i++;
			variable = ft_substr(str, j, i - j);
			if (variable[1] != '\0')
			{
				index = find_in_env(env, variable + 1);
				if (index != -1)
					new_str = str_replace(new_str, variable, get_variable_env(env, variable + 1));
				else if (new_str)
					new_str = remove_str_in_str(new_str, variable);
			}
			else if (str[i] == '\0')
				break ;
		}
		else
			i++;
	}
	return (new_str);
}

/* int main(int n, char **args, char **env) */
/* { */
/* 	ENV = dup_2d_array(env); */

/* 	char *str; */
/* 	char *s; */

/* 	while (1) */
/* 	{ */
/* 		str = readline("> "); */
/* 		s = replace_variable_with_value(ENV, str); */
/* 		printf ("%s\n", s); */
/* 	} */
/* } */

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
	free(tmp2);
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
			if (rl[i] == '\"')
				tmp = replace_variable_with_value(ENV, tmp);
			tmp = return_quoted_arg(rl, &i);
			splited_rd = add_element_2d_array_last(splited_rd, tmp);
		}
		else
		{
			tmp = return_unquoted_arg(rl, &i);
			tmp = replace_variable_with_value(ENV, tmp);
			splited_rd = split_and_join(splited_rd, tmp, ' ');
			free(tmp);
		}
		tmp = NULL;
	}
	return (splited_rd);
}
