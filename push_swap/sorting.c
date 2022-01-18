/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:47 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/10 19:41:24 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sort_a_sorted_array(t_stack *s)
{
	int		min_index;

	min_index = is_sorted_circulary(s->elements, s->n_elements);
	if (min_index == 0)
		return (0);
	if (min_index == -1)
		return (-1);
	if (s->n_elements - min_index < min_index)
		while (s->n_elements - min_index++)
			rotate_reverse (s, true);
	else
		while (min_index--)
			rotate (s, true);
	return (1);
}

int	best_move(t_stack s, int index)
{
	int		best_moves;

	best_moves = 0;
	if (index == 0)
		return (0);
	if (s.n_elements - index < index)
		while (s.n_elements - index++)
			best_moves++;
	else
		while (index--)
			best_moves--;
	return (best_moves);
}

void	start_sorting(t_stack *a, t_stack *b, int a_best, int b_best)
{
	while (min_int (absolute_value(a_best), absolute_value(b_best))
		&& (a_best * b_best > 0))
	{
		if (a_best < 0)
		{
			a_best++;
			b_best++;
			rr (a, b, true);
		}
		else
		{
			a_best--;
			b_best--;
			rrr (a, b, true);
		}
	}
	do_moves (a, a_best);
	do_moves (b, b_best);
	push_to (b, a, true);
}

void	sort_using_ls(t_stack *a, t_stack *b, int index, int min)
{
	int		nearest;
	int		a_best;
	int		b_best;
	int		current;

	while (b->n_elements)
	{
		while (index < b->n_elements)
		{
			nearest = nearest_number(*a, b->elements[index]);
			current = calc_moves (best_move (*a, nearest),
					best_move (*b, index));
			if (current < min || min == -1)
			{
				a_best = best_move (*a, nearest);
				b_best = best_move (*b, index);
				min = current;
			}
			index++;
		}
		index = 0;
		min = -1;
		start_sorting (a, b, a_best, b_best);
	}
}
