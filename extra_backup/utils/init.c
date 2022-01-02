/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 20:58:45 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:00:27 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

	a->player = mlx_xpm_file_to_image(con, "./assets/player.xpm", &w, &h);
	a->ground = mlx_xpm_file_to_image(con, "./assets/ground.xpm", &w, &h);
	a->rock = mlx_xpm_file_to_image(con, "./assets/rock.xpm", &w, &h);
	a->collect = mlx_xpm_file_to_image(con, "./assets/collect.xpm", &w, &h);
	a->exit = mlx_xpm_file_to_image(con, "./assets/exit.xpm", &w, &h);
	a->skel = mlx_xpm_file_to_image(con, "./assets/skel.xpm", &w, &h);
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
}
