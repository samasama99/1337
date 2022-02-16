/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:21:52 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/11 19:45:20 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	find_in_env(char **env, char *variable)
{
	char	*var;
	int		index;

	var = ft_strjoin(variable, "=");
	index = find_in_2d_array(env, var);
	free(var);
	return (index);
}

