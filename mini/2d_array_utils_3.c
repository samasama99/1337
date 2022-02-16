/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_2d_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:15:40 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/16 19:34:01 by orahmoun         ###   ########.fr       */
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
	if (elem == NULL)
		return (array);
	array = add_element_2d_array(array, elem, size_of_2d_array(array));
	return (array);
}

char	*join_2d_array_into_str(char **array)
{
	char	*joined;
	char	*tmp;
	size_t	i;

	i = 0;
	if (array == NULL)
		return (NULL);
	joined = ft_strdup("");
	while (array[i])
	{
		tmp = joined;
		joined = ft_strjoin(joined, array[i++]);
		free(tmp);
		tmp = NULL;
	}
	if (joined == NULL || *joined == '\0')
	{
		free(joined);
		joined = NULL;
		return (NULL);
	}
	return (joined);
}

char	**split_and_join(char **array, char *line, char c)
{
	char	**splited;

	if (line == NULL || *line == '\0')
		return (array);
	splited = ft_split(line, c);
	array = join_2d_array(array, splited);
	free(splited);
	splited = NULL;
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
