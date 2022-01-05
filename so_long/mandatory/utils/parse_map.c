/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:24:27 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/01 20:31:48 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header.h"

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
