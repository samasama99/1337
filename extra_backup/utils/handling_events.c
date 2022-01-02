/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 20:36:56 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:00:27 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_up_down(int movement)
{
	if (movement == UP_KEY)
		return (-1);
	if (movement == DOWN_KEY)
		return (1);
	return (0);
}

int	ft_right_left(int movement)
{
	if (movement == LEFT_KEY)
		return (-1);
	if (movement == RIGHT_KEY)
		return (1);
	return (0);
}

static int	player_movement(char **map, t_player *p, int movement, int *collect)
{
	int				current_x;
	int				current_y;
	int				collision;

	current_x = p->x_map;
	current_y = p->y_map;
	collision = check_collision (map, *p, movement, collect);
	if (collision == 1)
		return (0);
	else if (collision == 2)
		return (1);
	else if (collision == 3)
		return (3);
	p->x_map += ft_right_left (movement);
	p->y_map += ft_up_down (movement);
	map[current_y][current_x] = '0';
	map[p->y_map][p->x_map] = 'P';
	printf ("current moves : %d\n", ++p->moves);
	return (0);
}

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
	player_move = player_movement (info->map, &info->s_player, keycode,
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
