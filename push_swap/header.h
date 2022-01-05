/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:37:48 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/05 15:18:24 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# define ERROR_MSG_1 "Your List Contain A NonNumber !\n"
# define ERR1_LEN 32
# define ERROR_MSG_2 "You Need At Least 2 Arguments (Numbers)\n"
# define ERR2_LEN 40
# define ERROR_MSG_3 "All Numbers Should Be Unique\n"
# define ERR3_LEN 30

///// Vector Structure And The Related Functions /////
//////////////////////////////////////////////////////
typedef struct s_vec
{
	int		*elements;
	int		n_elements;
	int		capacity;
	char	*name;
}				t_vec;
typedef t_vec t_stack;
void	init_vec(t_vec *vec, char *name);
void	ft_realloc(t_vec *vec, int new_size);
void	insert_element(t_vec *vec, int element);
void    delete_element (t_vec *vec, int index);
//////////////////////////////////////////////////////

///// Moves  //////////////////////////////////////////
//////////////////////////////////////////////////////
void    swap_top(t_stack *s);
void    push_to(t_stack *src, t_stack *dst);
void    rotate(t_stack *s);
void    ss(t_stack *a, t_stack *b);
void    rr(t_stack *a, t_stack *b);
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
///// Moves Utils  ///////////////////////////////////
//////////////////////////////////////////////////////
void	swap (int *a, int *b);
void    write_move_name (char *t, char *name);
//////////////////////////////////////////////////////
#endif
