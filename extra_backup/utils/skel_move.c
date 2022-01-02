/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skel_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 07:32:06 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:14:01 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void random_path (int *l_r, int *u_d)
{
	if (rand() % 2)
	{
		if (rand() % 2 )
			*l_r = 1; 
		else
			*l_r = -1;
		*u_d = 0;
	}
	else
	{
		if (rand() % 2 )
			*u_d = 1; 
		else
			*u_d = -1;
		*l_r = 0;
	}
}

void	skel_move(void *param)
{
	t_info	*info;
	int number_skel;
	static int i;
	int l_r;
	int u_d;
	int	collision;
	
	info = (t_info *)param;
	number_skel = info->number_skels;
	l_r = 0;
	u_d = 0;
	if (i >= 200)
	{
		while (number_skel--)
		{
			random_path (&l_r, &u_d);
			collision = check_collision_foe (info->map, info->skels[number_skel], l_r, u_d);
			if (collision == 2)
			{
				printf ("You Lost!");
				free_all(*info);
			}
			if (collision == 1)
				continue;
			info->map[info->skels[number_skel].y_map][info->skels[number_skel].x_map] = '0';
			info->skels[number_skel].y_map = info->skels[number_skel].y_map + u_d;
			info->skels[number_skel].x_map = info->skels[number_skel].x_map + l_r;
			info->map[info->skels[number_skel].y_map][info->skels[number_skel].x_map] = 'F';
			l_r = 0;
			u_d = 0;
		}
		i = 0;
	}
	i++;
	printf ("--- %d\n", i);
}
