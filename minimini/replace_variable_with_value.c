/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable_with_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:48:43 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/18 21:47:31 by orahmoun         ###   ########.fr       */
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
	char	*tmp;
	char	*tmp2;

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
			while (str[i] && str[i] != '$' && str[i] != ' '
				&& str[i] != '\'' && str[i] != '\'')
				i++;
			variable = ft_substr(str, j, i - j);
			if (variable[1] != '\0')
			{
				index = find_in_env(env, variable + 1);
				tmp = new_str;
				if (index != -1)
				{
					tmp2 = get_variable_env(env, variable + 1);
					new_str = str_replace(new_str, variable, tmp2);
					/* free(tmp2); */
					tmp2 = NULL;
				}
				else if (new_str)
					new_str = remove_str_in_str(new_str, variable);
				/* free(tmp); */
				tmp = NULL;
			}
			else if (str[i] == '\0')
				break ;
			/* free(variable); */
			variable = NULL;
		}
		else
			i++;
	}
	/* free(str); */
	return (new_str);
}
