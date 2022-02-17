/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:19:52 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/17 17:55:37 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	**scanner(char *rl)
{
	char	**sp;
	char	**split_according;
	char	**res;
	char	*joined;
	size_t	i;

	i = 0;
	if (rl == NULL)
		return (NULL);
	sp = spilt_respecting_quotes(rl, ' ');
	res = init_2d_array();
	while (sp[i])
	{
		split_according = return_args_after_removing_quotes(sp[i]);
		joined = join_2d_array_into_str(split_according);
		free_2d_array(split_according);
		split_according = NULL;
		res = add_element_2d_array_last(res, joined);
		i++;
	}
	free_2d_array(sp);
	return (res);
}
