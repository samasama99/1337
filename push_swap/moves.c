/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:34 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 18:35:20 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap_top(t_stack *s, bool print)
{
	swap(&(s->elements[0]), &(s->elements[1]));
	if (print == true)
		write_move_name ("s", s->name);
}

void	push_to(t_stack *src, t_stack *dst)
{
	insert_element (dst, src->elements[0]);
	rotate_reverse (dst, false);
	delete_element (src, 0);
	write_move_name ("p", dst->name);
}

void	rotate(t_stack *s, bool print)
{
	int		t;
	int		i;

	i = 0;
	t = s->elements[0];
	while (i < s->n_elements - 1)
	{
		s->elements[i] = s->elements[i + 1];
		i++;
	}
	s->elements[i] = t;
	if (print)
		write_move_name ("r", s->name);
}

void	rotate_reverse(t_stack *s, bool print)
{
	int		t;
	int		i;

	i = s->n_elements - 1;
	t = s->elements[s->n_elements - 1];
	while (i > 0)
	{
		s->elements[i] = s->elements[i - 1];
		i--;
	}
	s->elements[0] = t;
	if (print)
		write_move_name ("rr", s->name);
}
