/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:01:34 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 19:01:36 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	check_error_init_mlx(void *check_error_return)
{
	if (check_error_return == NULL)
	{
		perror ("Error ");
		exit (-1);
	}
}

static void	check_error_window_mlx(void *check_error_return, void *connection)
{
	if (check_error_return == NULL)
	{
		perror ("Error ");
		mlx_destroy_window (connection, check_error_return);
		free (connection);
		exit (-1);
	}
}

static void	load_assets(t_assets *a, void *con)
{
	int	w;
	int	h;

	a->player_up = mlx_xpm_file_to_image(con, P_UP, &w, &h);
	a->player_down = mlx_xpm_file_to_image(con, P_DOWN, &w, &h);
	a->player_left = mlx_xpm_file_to_image(con, P_LEFT, &w, &h);
	a->player_right = mlx_xpm_file_to_image(con, P_RIGHT, &w, &h);
	a->player = a->player_down;
	a->skel = mlx_xpm_file_to_image(con, SKEL, &w, &h);
	a->ground = mlx_xpm_file_to_image(con, GROUND, &w, &h);
	a->rock = mlx_xpm_file_to_image(con, ROCK, &w, &h);
	a->collect = mlx_xpm_file_to_image(con, COLLECT, &w, &h);
	a->exit = mlx_xpm_file_to_image(con, EXIT, &w, &h);
}

static void	foe_calculation(t_info *info, int w, int h)
{
	int		skel;

	skel = 0;
	info->skels = (t_skel *)malloc (sizeof(t_skel) * info->number_skels);
	while (h < info->map_info.height)
	{
		while (w < info->map_info.width)
		{
			if (info->map[h][w] == 'F')
			{
				info->skels[skel].x_map = w;
				info->skels[skel].y_map = h;
				skel++;
			}
			w++;
		}
		w = 0;
		h++;
	}
}

void	init(t_info *info)
{
	t_mapinfo	map_info;

	map_info = info->map_info;
	info->connection = mlx_init();
	check_error_init_mlx (info->connection);
	info->window = mlx_new_window (info->connection,
			map_info.width * DEFAULT_SIZE,
			map_info.height * DEFAULT_SIZE + 30, "so_long");
	check_error_window_mlx (info->window, info->connection);
	load_assets (&info->assets, info->connection);
	foe_calculation(info, 0, 0);
}
