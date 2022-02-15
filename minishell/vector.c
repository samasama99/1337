/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:11:33 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/09 16:11:48 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*bf1;
	unsigned char	*bf2;
	size_t			i;

	i = 0;
	bf1 = dst;
	bf2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		bf1[i] = bf2[i];
		i++;
	}
	return (dst);
}

void	vec_free(t_vec *vec)
{
	int	i;

	i = 0;
	while (i < vec->n_elements)
	{
		free (vec->elements[i++]);
	}
	free (vec->elements);
	vec->elements = NULL;
	vec->n_elements = 0;
	vec->capacity = 1;
}

void	init_vec(t_vec *vec)
{
	vec->n_elements = 0;
	vec->capacity = 2;
	vec->elements = malloc (sizeof(void *) * (vec->capacity + 1));
}

static void	ft_realloc(t_vec *vec, int new_size)
{
	int		i;
	void	**new_elements;

	i = 0;
	new_elements = malloc (sizeof(void *) * (new_size + 1));
	while (!new_elements)
	{
		new_elements = malloc (sizeof(void *) * (new_size + 1));
	}
	ft_memcpy (new_elements, vec->elements,
		(new_size + 1) * sizeof (void *));
	free (vec->elements);
	vec->elements = new_elements;
}

void	insert_element(t_vec *vec, void *element)
{
	if (vec->n_elements == vec->capacity)
	{
		vec->capacity *= 2;
		ft_realloc (vec, vec->capacity);
	}
	vec->elements[vec->n_elements] = element;
	vec->n_elements++;
	vec->elements[vec->n_elements] = NULL;
}
/* #include <stdio.h> */
/* int main () */
/* { */
/* 	t_vec vec; */
/* 	char **ptr; */

/* 	init_vec (&vec); */
/* 	insert_element (&vec, strdup ("hello world !")); */
/* 	insert_element (&vec, strdup ("hello world !")); */
/* 	insert_element (&vec, strdup ("hello world !")); */
/* 	insert_element (&vec, strdup ("hello world !")); */
/* 	ptr = (char **)vec.elements; */

/* 	while (*ptr) */
/* 		printf ("%s\n", *(ptr++)); */
/* 	vec_free (&vec); */
/* } */
