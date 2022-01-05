/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:01:10 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 19:01:14 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus.h"
#include "draw_bonus.h"

void	draw_skel(t_assets a, t_info info, int w, int h)
{
	draw_ground (a, info, w, h);
	mlx_put_image_to_window (info.connection, info.window, a.skel, w, h);
}
