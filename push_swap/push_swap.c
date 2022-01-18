/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:22 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/11 15:19:04 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int n_args, char **args)
{
	t_stack		a;
	t_stack		b;
	t_stack		*tmp;

	tmp = NULL;
	if (n_args <= 1)
		return (1);
	parse_check_error(&a, &b, args, n_args);
	if (sort_a_sorted_array (&a) == -1)
	{
		if (a.n_elements <= 3)
			micro_sorting (&a);
		else if (a.n_elements < 6)
			sort_small_number (&a, &b);
		else
		{
			tmp = longest_sequence(a);
			push_non_sequence(&a, &b, *tmp);
			sort_using_ls(&a, &b, 0, -1);
			sort_a_sorted_array (&a);
		}
	}
	free_pair (a, b);
	if (tmp != NULL)
		free_single (tmp);
}
