/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:29:56 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/17 17:33:52 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*get_variable_env(char **env, char *variable)
{
	int	index;

	index = find_in_env(env, variable);
	if (index != -1)
		return (ft_strdup(ft_strchr(env[index], '=') + 1));
	return (NULL);
}
