/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:40:26 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/16 23:44:33 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_2d_array(char **array, int fd)
{
	int	i;

	i = 0;
	if (array != NULL)
		while (array[i])
		{
			ft_putstr_fd(array[i++], fd);
			ft_putstr_fd("\n", fd);
		}
}

size_t	size_of_2d_array(char **array)
{
	size_t	size;

	size = 0;
	if (array == NULL)
		return (0);
	while (array[size])
		size++;
	return (size);
}

char	**dup_2d_array(char **array)
{
	size_t		size;
	char		**dup;

	if (array == NULL)
		return (NULL);
	size = size_of_2d_array(array);
	dup = malloc (sizeof(char *) * size + 1);
	if (dup == NULL)
		return (NULL);
	while (size--)
		dup[size] = ft_strdup(array[size]);
	return (dup);
}

char	**delete_element_2d_array(char **array, size_t index)
{
	size_t		i;
	size_t		j;
	char		**new_array;

	i = 0;
	j = 0;
	if (array == NULL || *array == NULL)
		return (NULL);
	i = size_of_2d_array(array);
	new_array = malloc(sizeof(char *) * i);
	if (new_array == NULL || index > i)
		return (NULL);
	i = 0;
	while (array[j])
	{
		if (i == index)
			j++;
		new_array[i++] = array[j++];
	}
	new_array[i] = NULL;
	free(array[index]);
	free(array);
	return (new_array);
}

int	find_in_2d_array(char **array, char *str)
{
	int	i;

	if (array == NULL || str == NULL)
		return (-1);
	i = 0;
	while (array[i])
	{
		if (ft_strncmp(str, array[i], ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
