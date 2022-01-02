/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 02:00:27 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:05:47 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf ("%s", map[i++]);
}

void	init_info(t_info *info)
{
	info->map_info.collectables = 0;
	info->map_info.exits = 0;
	info->s_player.moves = 0;
	info->number_skels = 0;
}

void	free_all(t_info info)
{
	t_assets	assets;
	char		**map;

	map = info.map;
	assets = info.assets;
	mlx_destroy_image (info.connection, assets.ground);
	mlx_destroy_image (info.connection, assets.player);
	mlx_destroy_image (info.connection, assets.rock);
	mlx_destroy_image (info.connection, assets.exit);
	mlx_destroy_image (info.connection, assets.collect);
	mlx_destroy_window (info.connection, info.window);
	free (info.connection);
	while (info.map_info.height--)
		free (info.map[info.map_info.height]);
	free (map);
	exit(1);
}

int	loop_hook(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	skel_move (param);
	draw_map (info->map, *info);
	return (0);
}

int	main(int n, char **args)
{
	int		map_fd;
	char	**map;
	t_info	info;

	map_fd = open (args[1], O_RDONLY);
	if (n != 2 || check_ber (args[1]) != 0)
	{
		printf ("Please enter one '*.ber' map as an argument !");
		return (1);
	}
	if (map_fd < 0)
	{
		perror ("Error : ");
		return (1);
	}
	map = parse_map (map_fd);
	info.map = map;
	init_info (&info);
	if (check_map (map, &info) == -1)
		return (1);
	init (&info);
	handling_events(&info);
	mlx_loop_hook (info.connection, loop_hook, &info);
	mlx_loop (info.connection);
	return (0);
}
