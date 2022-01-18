/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:01:44 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/11 15:52:20 by orahmoun         ###   ########.fr       */
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
				print_err_exit(ERROR_MSG, ERR_LEN);
			}
		}
		i++;
	}
}

static void	check_init_stacks(char **args, int n_elems,
		t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	init_vec (a, "a");
	init_vec (b, "b");
	while (i < n_elems)
	{
		if (is_number(args[i]) && limit_error (ft_atoi (args[i])))
			insert_element(a, ft_atoi (args[i]));
		else
		{
			free_parse (args, a->n_elements);
			free (a->elements);
			free (b->elements);
			free (a->name);
			free (b->name);
			print_err_exit(ERROR_MSG, ERR_LEN);
		}
		i++;
	}
	number_repeat(a->elements, n_elems);
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

void	parse_check_error(t_stack *a, t_stack *b, char **args, int n_args)
{
	char		**parse;
	char		*buffer;
	int			i;
	int			n_elems;

	i = 1;
	buffer = ft_strdup ("");
	while (i < n_args)
	{
		buffer = str_append (buffer, args[i++]);
		buffer = str_append (buffer, " ");
	}
	parse = ft_split (buffer, ' ');
	n_elems = calc_splited_strings(buffer, ' ');
	free (buffer);
	check_init_stacks (parse, n_elems, a, b);
	free_parse (parse, n_elems);
}
