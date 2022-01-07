/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:47 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 21:48:04 by orahmoun         ###   ########.fr       */
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

static void	sort_using_ls_moves(t_stack *a, t_stack *b,
			int *a_moves, int *b_moves)
{
	int		index_min;
	int		size;
	int		*total_moves;

	total_moves = (int *)malloc(b->n_elements * sizeof(int));
	size = b->n_elements;
	while (size--)
	{
		if (a_moves[size] > b_moves[size])
			total_moves[size] = a_moves[size];
		else
			total_moves[size] = b_moves[size];
	}
	index_min = find_min (total_moves, b->n_elements);
	while (a_moves[index_min] > 0 && b_moves[index_min] > 0)
	{
		a_moves[index_min]--;
		b_moves[index_min]--;
		rr(a, b);
	}
	while (a_moves[index_min] > 0)
	{
		a_moves[index_min]--;
		rotate (a, true);
	}
	while (b_moves[index_min] > 0)
	{
		b_moves[index_min]--;
		rotate (b, true);
	}
	push_to(b, a);
}

void	sort_using_ls(t_stack *a, t_stack *b, int i, int j)
{
	int		min;
	int		*a_moves;
	int		*b_moves;

	a_moves = (int *)malloc (b->n_elements * sizeof(int));
	b_moves = (int *)malloc (b->n_elements * sizeof(int));
	min = -1;
	while (b->n_elements > 0)
	{
		while (i < b->n_elements)
		{
			while (j < a->n_elements)
			{
				if ((a->elements[j] - b->elements[i] < min
						&& a->elements[j] - b->elements[i] > 0) || min < 0)
				{
					min = a->elements[j] - b->elements[i];
					a_moves[i] = j;
					b_moves[i] = i;
				}
				j++;
			}
			min = -1;
			j = 0;
			i++;
		}
		i = 0;
		sort_using_ls_moves(a, b, a_moves, b_moves);
	}
	free (a_moves);
	free (b_moves);
}
