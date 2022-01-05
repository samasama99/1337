/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:00:13 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 19:00:16 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	equal_width(char **map, t_mapinfo *map_info)
{
	int	width;
	int	i;

	width = -1;
	i = 0;
	while (map[i])
	{
		if (width == -1)
			width = ft_strlen_remove_newline(map[i]);
		else if (width != ft_strlen_remove_newline(map[i]))
			return (-1);
		i++;
	}
	map_info->height = i;
	map_info->width = width;
	return (0);
}

static int	closed_map(char **map, t_mapinfo *map_info)
{
	int	w;
	int	h;

	w = map_info->width;
	h = map_info->height;
	if (h < 2 || w < 2)
		return (-1);
	while (w--)
		if (map[0][w] != '1')
			return (-1);
	while (h--)
		if (map[h][0] != '1')
			return (-1);
	w = map_info->width;
	h = map_info->height;
	while (w--)
		if (map[h - 1][w] != '1')
			return (-1);
	w = map_info->width;
	while (h--)
		if (map[h][w - 1] != '1')
			return (-1);
	return (1);
}

static int	check_characters(t_info *info, int h, int w, int p)
{
	while (h < info->map_info.height)
	{
		while (w < info->map_info.width)
		{
			if ((info->map[h][w] == 'P') && ++p)
			{
				info->s_player.x_map = w;
				info->s_player.y_map = h;
			}
			else if (info->map[h][w] == 'C')
				(info->map_info.collectables)++;
			else if (info->map[h][w] == 'E')
				(info->map_info.exits)++;
			else if (info->map[h][w] == 'F')
				(info->number_skels)++;
			else if (info->map[h][w] != '1' && info->map[h][w] != '0')
				return (-1);
			w++;
		}
		w = 0;
		h++;
	}
	if (p != 1 || info->map_info.collectables <= 0 || info->map_info.exits <= 0)
		return (-1);
	return (1);
}

int	check_map(char **map, t_info *info)
{
	t_mapinfo		*map_info;
	int				check_characters_return;

	map_info = &(info->map_info);
	if (equal_width (map, map_info) == -1)
	{
		printf ("Error\nthe map doesn't have equal lines\n");
		return (-1);
	}
	if (closed_map (map, map_info) == -1)
	{
		printf ("Error\nthe map is not completely closed\n");
		return (-1);
	}
	check_characters_return = check_characters (info, 0, 0, 0);
	if (check_characters_return == -1)
	{
		printf ("Error\n");
		printf ("Map should have one and only one player");
		printf(", and at lest one collectable and one exit\n");
		return (-1);
	}
	return (1);
}
