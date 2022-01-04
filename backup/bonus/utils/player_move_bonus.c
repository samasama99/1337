/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:46:08 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 14:55:22 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header_bonus.h"

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

static void	change_player_position_asset(int movement, t_assets *a)
{
	if (movement == UP_KEY)
		a->player = a->player_up;
	if (movement == DOWN_KEY)
		a->player = a->player_down;
	if (movement == LEFT_KEY)
		a->player = a->player_left;
	if (movement == RIGHT_KEY)
		a->player = a->player_right;
}

int	player_movement(t_info *info, t_player *p,
				int movement, int *collect)
{
	int				current_x;
	int				current_y;
	int				collision;
	char			**map;

	map = info->map;
	current_x = p->x_map;
	current_y = p->y_map;
	collision = check_collision (map, *p, movement, collect);
	if (collision == 1)
		return (0);
	else if (collision == 2)
		return (1);
	else if (collision == 3)
		return (3);
	change_player_position_asset (movement, &(info->assets));
	p->x_map += ft_right_left (movement);
	p->y_map += ft_up_down (movement);
	map[current_y][current_x] = '0';
	map[p->y_map][p->x_map] = 'P';
	++(p->moves);
	return (0);
}
