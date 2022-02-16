/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_2d_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:15:40 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/16 10:38:25 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

char	**init_2d_array(void)
{
	char	**init;

	init = malloc(sizeof(char *));
	*init = NULL;
	return (init);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (array != NULL)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}

static char	**add_element_to_last_2d_array(char **array, char *elem,
			size_t index, size_t size)
{
	char		**new_array;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	new_array = malloc(sizeof(char *) * (size + 2));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (array[j])
		new_array[i++] = array[j++];
	new_array[i] = elem;
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}

static char	**add_element_not_last_2d_array(char **array, char *elem,
			size_t index, size_t size)
{
	char		**new_array;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	new_array = malloc(sizeof(char *) * (size + 2));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (array[j])
	{
		if (i == index)
		{
			new_array[i] = elem;
			i++;
		}
		new_array[i++] = array[j++];
	}
	new_array[i] = NULL;
	free(array);
	return (new_array);
}

char	**add_element_2d_array(char **array, char *elem, size_t index)
{
	size_t		size;

	size = 0;
	if (array == NULL)
		return (NULL);
	while (array[size])
		size++;
	if (index > size)
		return (NULL);
	if (index == size)
		return (add_element_to_last_2d_array(array, elem, index, size));
	else
		return (add_element_not_last_2d_array(array, elem, index, size));
}

/* int main(int n, char **args, char **env) */
/* { */
/* 	char **dup = dup_2d_array(env); */
/* 	int		i = 0; */

/* 	while(dup[i]) */
/* 		i++; */
/* 	printf("%d\n", i); */
/* 	print_2d_array(dup); */
/* 	dup = add_element_2d_array(dup, ft_strdup("X=10"), i); */
/* 	if (dup == NULL) */
/* 		exit(1); */
/* 	dup = add_element_2d_array(dup, ft_strdup("X=10"), 0); */
/* 	dup = add_element_2d_array(dup, ft_strdup("X=10"), 5); */
/* 	printf("\n"); */
/* 	print_2d_array(dup); */
/* 	free_2d_array(dup); */
/* 	while(1); */
/* 	return 0; */
/* } */
