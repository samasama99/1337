/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:01:40 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 19:01:49 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

char	**parse_map(int map_fd)
{
	char	**map;
	int		height;
	int		i;

	i = 0;
	height = 0;
	map = (char **)malloc (sizeof(char *) * 2);
	if (map == NULL)
	{
		perror ("Error ");
		exit (1);
	}
	map[height] = get_next_line (map_fd);
	while (map[height])
	{
		map = (char **)ft_realloc ((void **)map, ++height);
		map[height] = get_next_line (map_fd);
	}
	return (map);
}
