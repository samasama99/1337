/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 20:36:56 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/03 22:53:54 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static int	key_hook(int keycode, void *param)
{
	t_info	*info;
	int		player_move;

	info = (t_info *)param;
	if (keycode == ESC)
		free_all (*((t_info *) info));
	if (keycode != DOWN_KEY && keycode != UP_KEY
		&& keycode != LEFT_KEY && keycode != RIGHT_KEY)
		return (1);
	player_move = player_movement (info, &info->s_player, keycode,
			&info->map_info.collectables);
	if (player_move == 1)
		free_all (*info);
	else if (player_move == 3)
	{
		printf ("You Lost !\n");
		free_all (*info);
	}
	return (0);
}

void	handling_events(t_info *info)
{
	mlx_hook (info->window, 2, 1L << 0, key_hook, info);
}
