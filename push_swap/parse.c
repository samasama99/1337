/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:01:44 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 22:08:51 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

static void	number_repeat(int *array, int n_elems)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < n_elems - 1)
	{
		j = i + 1;
		while (j < n_elems)
		{
			if (array[i] == array[j++])
			{
				// free_parse ();
				print_err_exit(ERROR_MSG_3, ERR3_LEN);
			}
		}
		i++;
	}
}

static void	check_init_stacks(char **args, int n_args,
		t_stack *a, t_stack *b)
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
			free (a->elements);
			free (b->elements);
			// free_parse ();
			print_err_exit(ERROR_MSG_2, ERR2_LEN);
		}
		i++;
	}
	number_repeat(a->elements, n_args);
}

static int	calc_splited_strings(char *s, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			total++;
	}
	return (total);
}

void parse_check_error(t_stack *a, t_stack *b, char **args, int n_args)
{
	char		**parse;
	int			n_splited;

	if (n_args == 2)
	{
		n_splited = calc_splited_strings(args[1], ' ');
		if (n_splited < 2)
			print_err_exit(ERROR_MSG_4, ERR4_LEN);
		parse = ft_split (args[1], ' ');
		check_init_stacks(parse, n_splited, a, b);
	}
	else if (n_args > 2)
	{
		parse = dup_2d_strings_array(args + 1, n_args - 1);
		check_init_stacks (parse, n_args - 1, a, b);
	}
	else if (n_args < 2)
		print_err_exit(ERROR_MSG_2, ERR2_LEN);
	// free_pasre ();
}
