/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:22 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 22:00:23 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int n_args, char **args)
{
	t_stack		a;
	t_stack		b;
	t_stack		*tmp;
	parse_check_error(&a, &b, args, n_args);
	if (sort_a_sorted_array (&a) == -1)
	{
		tmp = longest_sequence(a);
		push_non_sequence(&a, &b, *tmp);
		sort_using_ls(&a, &b, 0, 0);
		sort_a_sorted_array (&a);
	}
}
