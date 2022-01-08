/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:47 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/08 11:29:04 by orahmoun         ###   ########.fr       */
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
	return min_index;
}

int	best_move(t_stack s, int index)
{
	int		best_moves;

	best_moves = 0;
	if (index == 0)
		return 0;
	if (s.n_elements - index < index)
		while (s.n_elements - index++)
			best_moves++;
	else
		while (index--)
			best_moves--;

	return best_moves;
}

int max_int (int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int min_int (int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int	absolute_value(int x)
{
	if (x < 0)
		x *= - 1;
	return x;
}

int calc_moves (int a_best, int b_best)
{
	int		moves;

	if (a_best * b_best < 0)
		moves = absolute_value(a_best) + absolute_value(b_best);
	else
		moves = max_int (absolute_value(a_best), absolute_value(b_best));
	return moves;
}

void	do_moves (t_stack *s, int moves)
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
void	start_sorting(t_stack *a, t_stack *b, int a_best, int b_best)
{

	if (a_best * b_best < 0)
	{
		do_moves (a, a_best);
		do_moves (b, b_best);
	}
	else
	{
		while (min_int (absolute_value(a_best), absolute_value(b_best)))
		{
			if (a_best < 0)
			{
				a_best++;
				b_best++;
				rr (a, b);
			}
			else
			{
				a_best--;
				b_best--;
				rrr (a ,b);
			}
		}
		do_moves (a, a_best);
		do_moves (b, b_best);
	}
	push_to (b, a);
	return ;
}


void	sort_using_ls(t_stack *a, t_stack *b)
{
	int		nearest;
	int		a_current_moves;
	int		b_current_moves;
	int		a_best;
	int		b_best;
	int		index;
	int		current;
	int		min;
	
	index = 0;
	min = -1;
	int index2 = 0;
	while (b->n_elements)
	{
		while (index < b->n_elements)
		{
			nearest = nearest_number(*a, b->elements[index]);
			a_current_moves = best_move (*a, nearest);
			b_current_moves = best_move (*b, index);
			
			current = calc_moves (a_current_moves, b_current_moves);
			
			if (current < min ||  min == -1)
			{
				a_best = a_current_moves;
				b_best = b_current_moves;
				min = current;
				if (min == 0)
					break ;
			}
			index++;
		}
		index = 0;
		index2++;
		start_sorting (a, b, a_best, b_best);
		min = -1;
	}
}
