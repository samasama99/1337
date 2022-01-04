/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skel_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 07:32:06 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/03 22:33:02 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"

static void	random_path(int *l_r, int *u_d)
{
	if (rand() % 2)
	{
		if (rand() % 2)
			*l_r = 1;
		else
			*l_r = -1;
		*u_d = 0;
	}
	else
	{
		if (rand() % 2)
			*u_d = 1;
		else
			*u_d = -1;
		*l_r = 0;
	}
}

static void	change_skel_postion(char **map, t_skel *skel, int *l_r, int *u_d)
{
	map[skel->y_map][skel->x_map] = '0';
	skel->y_map = skel->y_map + *u_d;
	skel->x_map = skel->x_map + *l_r;
	map[skel->y_map][skel->x_map] = 'F';
	*l_r = 0;
	*u_d = 0;
}

void	skel_move(t_info *info, int l_r, int u_d, int number_skel)
{
	static int		i;
	int				collision;

	number_skel = info->number_skels;
	if (i >= 150)
	{
		while (number_skel--)
		{
			random_path (&l_r, &u_d);
			collision = check_collision_foe (info->map,
					info->skels[number_skel], l_r, u_d);
			if (collision == 2)
			{
				printf ("You Lost!");
				free_all(*info);
			}
			if (collision == 1)
				continue ;
			change_skel_postion (info->map, &(info->skels[number_skel]),
				&l_r, &u_d);
		}
		i = 0;
	}
	i++;
}
