/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:21 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/10 20:59:21 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	nearest_number(t_stack s, int number)
{
	int		index;
	int		min_sub;
	int		min_index;
	int		current_sub;

	min_sub = -1;
	index = 0;
	while (index < s.n_elements)
	{
		current_sub = s.elements[index] - number;
		if ((current_sub < min_sub && current_sub > 0)
			|| (current_sub > 0 && min_sub < 0))
		{
			min_sub = current_sub;
			min_index = index;
		}
		index++;
	}
	return (min_index);
}

int	calc_moves(int a_best, int b_best)
{
	int		moves;

	if (a_best * b_best < 0)
		moves = absolute_value(a_best) + absolute_value(b_best);
	else
		moves = max_int (absolute_value(a_best), absolute_value(b_best));
	return (moves);
}

void	do_moves(t_stack *s, int moves)
{
	while (moves < 0)
	{
		++moves;
		rotate (s, true);
	}
	while (moves > 0)
	{
		--moves;
		rotate_reverse (s, true);
	}
}
