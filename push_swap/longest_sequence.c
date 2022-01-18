/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:27:20 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/10 20:59:18 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_stack	*longest_sequence_index(t_stack s, int index)
{
	int			i;
	t_stack		*seq;

	i = (index + 1) % s.n_elements;
	seq = (t_stack *)malloc(sizeof (t_stack));
	init_vec (seq, "x");
	insert_element(seq, s.elements[index]);
	while ((i - index - 1) < s.n_elements)
	{
		if (s.elements[(i % s.n_elements)] > seq->elements[seq->n_elements - 1])
			insert_element (seq, s.elements[i % s.n_elements]);
		i++;
	}
	return (seq);
}

static bool	in_sequence(int elem, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (elem == array[i++])
			return (true);
	return (false);
}

void	push_non_sequence(t_stack *src, t_stack *dst, t_stack seq)
{
	int	i;
	int	iteration;

	iteration = src->n_elements;
	i = 0;
	while (i < iteration)
	{
		if (in_sequence(*(src->elements), seq.elements, seq.n_elements))
			rotate (src, true);
		else
			push_to(src, dst, true);
		i++;
	}
}

t_stack	*longest_sequence(t_stack s)
{
	t_stack		*tmp1;
	t_stack		*tmp2;
	int			len;
	int			i;

	i = 0;
	len = 0;
	tmp2 = NULL;
	while (i < s.n_elements)
	{
		tmp1 = longest_sequence_index (s, i);
		if (tmp1->n_elements > len)
		{
			len = tmp1->n_elements;
			if (tmp2 != NULL)
				free_single (tmp2);
			tmp2 = tmp1;
		}
		else
			free_single (tmp1);
		i++;
	}
	return (tmp2);
}
