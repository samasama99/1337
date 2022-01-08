/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:17:28 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 21:48:03 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	find_min(int *array, int size)
{
	int			min;
	int			min_index;
	int			i;

	i = 1;
	min = array[0];
	min_index = 0;
	while (i < size)
	{
		if (min > array[i])
		{
			min = array[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

/* int	find_max(int *array, int size) */
/* { */
/* 	int			max; */
/* 	int			max_index; */
/* 	int			i; */

/* 	i = 1; */
/* 	max = array[0]; */
/* 	max_index = 0; */
/* 	while (i < size) */
/* 	{ */
/* 		if (max < array[i]) */
/* 		{ */
/* 			max = array[i]; */
/* 			max_index = i; */
/* 		} */
/* 		i++; */
/* 	} */
/* 	return (max_index); */
/* } */

int	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 2)
	{
		if (array[i] > array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	is_sorted_circulary(int	*array, int size)
{
	int		i;
	int		min_index;

	min_index = find_min (array, size);
	i = min_index + 1;
	while ((i + 1) % size != min_index)
	{
		if (array[i % size] > array[(i + 1) % size])
			return (-1);
		i++;
	}
	return (min_index);
}

/* static void is_true(bool pr) */
/* { */
/* 	if (pr) */
/* 		printf ("True  !\n"); */
/* 	else */
/* 		printf ("False !\n"); */
/* } */
