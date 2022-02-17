/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:39:42 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/15 18:39:47 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_vec
{
	void	**elements;
	int		n_elements;
	int		capacity;
}				t_vec;

void	vec_free(t_vec *vec);
void	init_vec(t_vec *vec);
void	insert_element(t_vec *vec, void *element);
#endif
