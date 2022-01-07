/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:37:48 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/07 21:59:38 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdbool.h> 
# define ERROR_MSG_1 "Your List Contain A Non Number !\n"
# define ERR1_LEN 33
# define ERROR_MSG_2 "You Need At Least 1 Argument (Numbers)\n"
# define ERR2_LEN 40
# define ERROR_MSG_3 "All Numbers Should Be Unique\n"
# define ERR3_LEN 30
# define ERROR_MSG_4 "You Need At Least 2 Numbers\n"
# define ERR4_LEN 28
# define ERROR_MSG_5 "Malloc Error !\n"
# define ERR5_LEN 15
# define STDERROR 2

///// Vector Structure And The Related Functions /////
//////////////////////////////////////////////////////
typedef struct s_vec
{
	int		*elements;
	int		n_elements;
	int		capacity;
	char	*name;
}				t_vec;
typedef t_vec	t_stack;
void	init_vec(t_vec *vec, char *name);
void	ft_realloc(t_vec *vec, int new_size);
void	insert_element(t_vec *vec, int element);
void	delete_element(t_vec *vec, int index);
t_vec	*dup_vec(t_vec vec);

///// Moves Utils  ///////////////////////////////////
//////////////////////////////////////////////////////
void	swap(int *a, int *b);
void	write_move_name(char *t, char *name);

///// Moves  //////////////////////////////////////////
//////////////////////////////////////////////////////
void	swap_top(t_stack *s, bool print);
void	rotate(t_stack *s, bool print);
void	rotate_reverse(t_stack *s, bool print);
void	push_to(t_stack *src, t_stack *dst);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

///// Sorting Functions //////////////////////////////
//////////////////////////////////////////////////////
void	normal_sorting(t_stack *a, t_stack *b);
int		is_sorted_circulary(int *array, int size);
int		find_min(int *array, int size);
int		find_max(int *array, int size);
int		sort_a_sorted_array(t_stack *s);
t_stack	*longest_sequence_index(t_stack s, int index);
t_stack	*longest_sequence(t_stack s);
void	push_non_sequence(t_stack *src, t_stack *dst, t_stack seq);
void	sort_using_ls(t_stack *a, t_stack *b, int i, int j);

///// Parsing And Checking Errors ////////////////////
//////////////////////////////////////////////////////
void	parse_check_error(t_stack *a, t_stack *b, char **args, int n_args);

///// Extra Utils ////////////////////////////////////
//////////////////////////////////////////////////////
void	print_err_exit(char *err, int err_len);
char	**dup_2d_strings_array(char **args, int n_elems);

#endif
