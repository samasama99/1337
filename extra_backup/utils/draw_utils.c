/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:45:25 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:00:27 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	draw_ground(t_assets a, t_info info, int w, int h)
{
	mlx_put_image_to_window (info.connection, info.window, a.ground, w, h);
}

void	draw_player(t_assets a, t_info info, int w, int h)
{
	draw_ground (a, info, w, h);
	mlx_put_image_to_window (info.connection, info.window, a.player, w, h);
}

void	draw_rock(t_assets a, t_info info, int w, int h)
{
	mlx_put_image_to_window (info.connection, info.window, a.rock, w, h);
}

void	draw_exit(t_assets a, t_info info, int w, int h)
{
	draw_ground (a, info, w, h);
	mlx_put_image_to_window (info.connection, info.window, a.exit, w, h);
}

void	draw_collect(t_assets a, t_info info, int w, int h)
{
	draw_ground (a, info, w, h);
	mlx_put_image_to_window (info.connection, info.window, a.collect, w, h);
}
