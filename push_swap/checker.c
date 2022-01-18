/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:58:10 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/11 15:12:58 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**read_instructions(void)
{
	char	*buffer;
	char	*tmp;
	char	**parse;

	tmp = ft_strdup("");
	while (true)
	{
		buffer = get_next_line (0);
		if (buffer == NULL)
			break ;
		if (move_exist (buffer) == 0)
			return (NULL);
		tmp = str_append (tmp, buffer);
		free (buffer);
	}
	parse = ft_split (tmp, '\n');
	if (tmp)
		free (tmp);
	return (parse);
}

void	check_if_sorted(char **parse, t_stack *a, t_stack *b, int n_elems)
{
	int		n_parsed;

	n_parsed = 0;
	while (parse[n_parsed])
		n_parsed++;
	if (parse != 0)
	{
		if (testing_moves (parse, a, b) == -1)
			write (1, "Error\n", 5);
		else if (is_sorted (a->elements, a->n_elements)
			&& n_elems == a->n_elements)
			printf ("ok\n");
		else
			printf ("ko\n");
		free_parse (parse, n_parsed);
	}
}

int	main(int n_args, char **args)
{
	t_stack		a;
	t_stack		b;
	int			i;
	char		**parse;
	int			n_elems;

	if (n_args < 2)
		return (1);
	parse = NULL;
	i = 0;
	parse_check_error(&a, &b, args, n_args);
	n_elems = a.n_elements;
	parse = read_instructions ();
	if (parse != NULL)
		check_if_sorted (parse, &a, &b, n_elems);
	else
		write (1, "Error\n", 5);
	free_pair (a, b);
}
