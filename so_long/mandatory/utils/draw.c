/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 20:01:30 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 18:44:22 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include "draw.h"

static void	draw_component(char **map,	t_info info, int x, int y)
{
	int			w;
	int			h;
	t_assets	assets;

	assets = info.assets;
	w = x * DEFAULT_SIZE;
	h = y * DEFAULT_SIZE;
	if (map[y][x] == '1')
		draw_rock (assets, info, w, h);
	if (map[y][x] == 'P')
		draw_player (assets, info, w, h);
	if (map[y][x] == 'E')
		draw_exit (assets, info, w, h);
	if (map[y][x] == 'C')
		draw_collect (assets, info, w, h);
	if (map[y][x] == '0')
		draw_ground (assets, info, w, h);
}

void	draw_map(char **map, t_info info)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	mlx_clear_window (info.connection, info.window);
	while (map[y])
	{
		while (map[y][x] && map[y][x] != '\n')
		{
			draw_component (map, info, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
