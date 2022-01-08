/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:13:27 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 21:48:01 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_err_exit(char *err, int err_len)
{
	write (STDERROR, err, err_len);
	exit(1);
}

char	**dup_2d_strings_array(char **args, int n_elems)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc (sizeof(char *) * n_elems);
	if (new == NULL)
		print_err_exit (ERROR_MSG_5, ERR5_LEN);
	while (i < n_elems)
	{
		new[i] = ft_strdup(args[i]);
		i++;
	}
	return (new);
}
