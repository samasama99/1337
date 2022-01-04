/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:34:36 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/01 21:38:57 by orahmoun         ###   ########.fr       */
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
	{
		--(*collect);
	}
	return (0);
}
