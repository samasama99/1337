/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:20:49 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/05 15:15:25 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static int	is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (ft_isdigit (arg[i]))
		i++;
	return (!arg[i]);
}

int number_repeat(int *array, int n_elems)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < n_elems - 1)
	{
		j = i + 1;
		while (j < n_elems)
			if (array[i] == array[j++])
				return (0);
		i++;
	}
	return (1);
}

static void	check_init_stacks(char **args, int n_args, t_stack *a, t_stack *b)
{
	int	i;

	init_vec (a, "a");
	init_vec (b, "b");
	i = 0;
	while (i < n_args)
	{
		if (is_number(args[i]))
			insert_element(a, ft_atoi (args[i]));
		else
		{
			write (2, ERROR_MSG_1, ERR1_LEN);
			free (a->elements);
			free (b->elements);
			exit (1);
		}
		i++;
	}
}

static void	print_stack (t_stack s)
{
	int	i;

	i = 0;
	write (1, s.name, 1);
	write (1, " :\n", 3);
	while (i < s.n_elements)
	{
		ft_putnbr_fd (s.elements[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}

int	main(int n, char **args)
{
	t_stack		a;
	t_stack		b;

	if (n > 2)
		check_init_stacks (args + 1, n - 1, &a, &b);
	else
	{
		write (2, ERROR_MSG_2, ERR2_LEN);
		exit (1);
	}
	if (number_repeat(a.elements, n - 1) == 0)
	{
		write (2, ERROR_MSG_3, ERR3_LEN);
		exit (1);
	}
	/* print_stack (a); */
	/* push_to (&a, &b); */
	/* print_stack (a); */
	/* print_stack (b); */
	/* swap_top (&a); */
	print_stack (a);
	rotate (&a);
	print_stack (a);
	return (0);
}
