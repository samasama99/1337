/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:56:02 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/04 18:56:17 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H	
# define DRAW_BONUS_H
# include "../header_bonus.h"

void	draw_ground(t_assets a, t_info info, int w, int h);
void	draw_player(t_assets a, t_info info, int w, int h);
void	draw_rock(t_assets a, t_info info, int w, int h);
void	draw_exit(t_assets a, t_info info, int w, int h);
void	draw_collect(t_assets a, t_info info, int w, int h);
void	draw_skel(t_assets a, t_info info, int w, int h);
#endif
