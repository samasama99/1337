/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:35:11 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 18:35:18 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ss(t_stack *a, t_stack *b)
{
	swap_top(a, false);
	swap_top(b, false);
	write (1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, false);
	rotate(b, false);
	write (1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate_reverse(a, false);
	rotate_reverse(b, false);
	write (1, "rrr\n", 4);
}
