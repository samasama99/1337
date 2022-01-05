/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:00:58 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 19:01:06 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"
#include "draw_bonus.h"

static int	rgb_color(unsigned char b, unsigned char g, unsigned char r)
{
	int				color;
	unsigned char	*cl;

	cl = (unsigned char *)&color;
	*cl = b;
	*(cl + 1) = g;
	*(cl + 2) = r;
	return (color);
}

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
	if (map[y][x] == 'F')
		draw_skel (assets, info, w, h);
}

void	draw_counter(t_info info, int version)
{
	char		*msg;
	char		*counter;
	char		*current;
	char		*total_collects;
	static int	total;

	if (total == 0 && info.map_info.collectables)
		total = info.map_info.collectables;
	counter = ft_itoa(info.s_player.moves);
	total_collects = ft_itoa(total);
	current = ft_itoa(total - info.map_info.collectables);
	msg = ft_strjoin_string (version, "the current moves : ", counter,
			"  ----  you collected : ", current, " / ", total_collects);
	mlx_string_put(info.connection, info.window, 10,
		info.map_info.height * DEFAULT_SIZE, rgb_color(0, 240, 0), msg);
	free (msg);
	free (counter);
	free (total_collects);
	free (current);
	msg = NULL;
	counter = NULL;
	current = NULL;
	total_collects = NULL;
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
	if (info.map_info.width * DEFAULT_SIZE < 550)
		draw_counter (info, 2);
	else
		draw_counter (info, 6);
}
