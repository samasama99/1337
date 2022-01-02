/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 21:13:58 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/02 08:00:51 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H	
# define DRAW_H
# include "../header.h"

void	draw_ground(t_assets a, t_info info, int w, int h);
void	draw_player(t_assets a, t_info info, int w, int h);
void	draw_rock(t_assets a, t_info info, int w, int h);
void	draw_exit(t_assets a, t_info info, int w, int h);
void	draw_collect(t_assets a, t_info info, int w, int h);
void	draw_skel(t_assets a, t_info info, int w, int h);
#endif
