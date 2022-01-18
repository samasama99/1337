/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:04:37 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/11 15:54:03 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_parse(char **args, int n_elems)
{
	while (n_elems)
		free (args[--n_elems]);
	free (args);
}

void	free_pair(t_stack a, t_stack b)
{
	free (a.elements);
	free (b.elements);
	free (a.name);
	free (b.name);
}

void	free_single(t_stack *s)
{
	free (s->name);
	free (s->elements);
	free (s);
}

int	limit_error(long long x)
{
	if (x > INT_MAX || x < INT_MIN)
		return (0);
	return (1);
}
