/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:54:41 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/16 10:32:19 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	**ft_unset(char **env, char *variable)
{
	size_t	index;

	index = find_in_2d_array(env, variable);
	if (index == -1)
		return (NULL);
	return (delete_element_2d_array(env , index));
}
