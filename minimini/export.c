/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:54:51 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/17 14:27:58 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**ft_export(char **env, char *new_elem)
{
	size_t	size;
	size_t	index;
	char	*tmp;

	size = 0;
	if (env == NULL || new_elem == NULL || *new_elem == '\0')
		return (env);
	size = size_of_2d_array(env);
	if (ft_strchr(new_elem, '=') == NULL)
	{
		free(new_elem);
		return (env);
	}
	tmp = ft_substr(new_elem, 0, ft_strchr(new_elem, '=') - new_elem);
	index = find_in_env(env, tmp);
	free(tmp);
	if (index == -1)
		return (add_element_2d_array(env, new_elem, size - 1));
	free(env[index]);
	env[index] = new_elem;
	return (env);
}

/* int main(int n, char **args, char **env) */
/* { */
/* 	char **dup = dup_2d_array(env); */

/* 	print_2d_array(dup); */
/* 	dup = ft_export(dup, ft_strdup("LESS=10")); */
/* 	dup = ft_export(dup, ft_strdup("oussama=10")); */
/* 	dup = ft_export(dup, ft_strdup("test 10")); */
/* 	dup = ft_export(dup, ft_strdup("oussama=hello world")); */
/* 	dup = ft_export(dup, ft_strdup("hello=mmmmmm")); */
/* 	if (dup == NULL) */
/* 		exit(1); */
/* 	printf("---------------\n"); */
/* 	print_2d_array(dup); */
/* 	free_2d_array(dup); */
/* 	while (1); */
/* 	return 0; */
/* } */
