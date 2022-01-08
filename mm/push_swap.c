/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:22 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/08 11:29:03 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* static void	print_stack (t_stack s) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	write (1, s.name, 1); */
/* 	write (1, " :\n", 3); */
/* 	while (i < s.n_elements) */
/* 	{ */
/* 		ft_putnbr_fd (s.elements[i++], 1); */
/* 		ft_putchar_fd('\n', 1); */
/* 	} */
/* } */

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
		sort_using_ls(&a, &b);
		sort_a_sorted_array (&a);
	}
	// free_stack ();
}
