/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:54:41 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/12 19:59:15 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	**ft_unset(char **env, char *variable)
{
	size_t	index;

	index = find_in_2d_array(env, variable);
	if (index == -1)
		return (NULL);
	return (delete_element_2d_array(env , index));
}


int main(int n, char **args, char **env)
{
	char **dup = dup_2d_array(env);

	print_2d_array(dup, 1);
	dup = ft_export(dup, ft_strdup("LESS=10"));
	dup = ft_export(dup, ft_strdup("oussama=10"));
	dup = ft_export(dup, ft_strdup("test 10"));
	dup = ft_export(dup, ft_strdup("oussama=hello world"));
	dup = ft_export(dup, ft_strdup("hello=mmmmmm"));
	if (dup == NULL)
		exit(1);
	printf("---------------\n");
	print_2d_array(dup, 1);
	dup = ft_unset(dup, "LESS");
	dup = ft_unset(dup, "hello");
	printf("---------------\n");
	print_2d_array(dup, 1);
	free_2d_array(dup);
	while (1);
	return 0;
}
