/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 18:35:30 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(int *a, int *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

void	write_move_name(char *t, char *name)
{
	write (1, t, ft_strlen(t));
	write (1, name, 1);
	write (1, "\n", 1);
}
