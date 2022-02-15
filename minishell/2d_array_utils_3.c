/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_2d_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:15:40 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/14 14:14:47 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	**join_2d_array(char **dst, char **source)
{
	size_t	i;

	if (dst == NULL)
		return (NULL);
	i = 0;
	while (source[i])
	{
		dst = add_element_2d_array(dst, source[i], size_of_2d_array(dst));
		i++;
	}
	return (dst);
}

char	**add_element_2d_array_last(char **array, char *elem)
{
	if (array == NULL)
		return (NULL);
	if (elem == NULL || *elem == '\0')
		return (array);
	array = add_element_2d_array(array, elem, size_of_2d_array(array));
	return (array);
}

/* int main(int n, char **args, char **env) */
/* { */
/* 	char *rd1 = readline("> "); */
/* 	char *rd2 = readline("> "); */

/* 	char **s_rd1 = ft_split(rd1, ' '); */
/* 	char **s_rd2 = ft_split(rd2, ' '); */

/* 	char **test = join_2d_array(s_rd1, s_rd2); */

/* 	test = add_element_2d_array_last(test, "hello"); */
/* 	print_2d_array(test, 1); */
/* } */
