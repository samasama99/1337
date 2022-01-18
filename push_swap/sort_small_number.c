/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:25:43 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/10 21:02:21 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:51:02 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/10 19:24:44 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_half(t_stack *a, t_stack *b)
{
	int	half;
	int	max_half;
	int	max_index;

	max_half = a->n_elements / 2;
	while (a->n_elements > max_half)
	{
		half = a->n_elements / 2;
		max_index = find_max (a->elements, a->n_elements);
		if (max_index < half)
			max_index = (-max_index);
		else
			max_index = a->n_elements - max_index;
		do_moves (a, max_index);
		push_to (a, b, true);
		if (b->n_elements >= 2)
			rotate (b, true);
	}
}

void	micro_sorting(t_stack *a)
{
	swap_top (a, true);
	sort_a_sorted_array (a);
}

void	sort_small_number(t_stack *a, t_stack *b)
{
	while (a->n_elements != 3)
	{
		if (find_max (a->elements, a->n_elements) == 0)
			rotate (a, true);
		push_to (a, b, true);
	}
	if (is_sorted_circulary(a->elements, a->n_elements) == -1)
		swap_top (a, true);
	sort_using_ls (a, b, 0, -1);
	sort_a_sorted_array(a);
}
