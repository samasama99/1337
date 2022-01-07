/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:24 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 18:36:32 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_vec(t_vec *vec, char *name)
{
	vec->n_elements = 0;
	vec->capacity = 2;
	vec->elements = malloc (sizeof(int) * (vec->capacity + 1));
	vec->name = ft_strdup(name);
}

void	ft_realloc(t_vec *vec, int new_size)
{
	int		i;
	void	*new_elements;

	i = 0;
	new_elements = malloc (sizeof(int) * (new_size + 1));
	while (!new_elements)
	{
		new_elements = malloc (sizeof(int) * (new_size + 1));
	}
	ft_memcpy (new_elements, vec->elements,
		(new_size + 1) * sizeof (int));
	free (vec->elements);
	vec->elements = new_elements;
}

void	insert_element(t_vec *vec, int element)
{
	if (vec->n_elements == vec->capacity)
	{
		vec->capacity *= 2;
		ft_realloc (vec, vec->capacity);
	}
	vec->elements[vec->n_elements] = element;
	vec->n_elements++;
}

void	delete_element(t_vec *vec, int index)
{
	--vec->n_elements;
	while (index < vec->n_elements)
	{
		vec->elements[index] = vec->elements[index + 1];
		index++;
	}
}

t_vec	*dup_vec(t_vec vec)
{
	t_vec	*dup;

	dup = (t_vec *)malloc (sizeof (t_vec));
	dup->elements = (int *)malloc (sizeof(int) * vec.capacity);
	ft_memcpy (dup->elements, vec.elements, vec.n_elements * sizeof (int));
	dup->n_elements = vec.n_elements;
	dup->name = vec.name;
	dup->capacity = vec.capacity;
	return (dup);
}
