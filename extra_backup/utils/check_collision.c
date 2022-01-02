/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:34:36 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:12:44 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_collision(char **map, t_player p, int movement, int *collect)
{
	int		x;
	int		y;

	x = p.x_map + ft_right_left (movement);
	y = p.y_map + ft_up_down (movement);
	if (map[y][x] == 'E')
	{
		if (*collect == 0)
		{
			printf ("--- You Won !\n");
			return (2);
		}
		return (1);
	}
	if (map[y][x] == '1')
		return (1);
	if (map[y][x] == 'C')
		--(*collect);
	if (map[y][x] == 'F')
		return (3);
	return (0);
}

int	check_collision_foe(char **map, t_skel s, int l_r, int u_d)
{
	int		x;
	int		y;

	x = s.x_map + l_r;
	y = s.y_map + u_d;
	if (map[y][x] == 'E' || map[y][x] == '1' || map[y][x] == 'C')
		return (1);
	if (map[y][x] == 'P')
		return (2);
	return (0);
}
