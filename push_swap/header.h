/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:37:48 by orahmoun          #+#    #+#             */
/*   Updated: 2022/01/11 15:54:59 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h> 
# include <limits.h>
# include "libft/libft.h"
# define ERROR_MSG "Error\n"
# define ERR_LEN 6
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
void	push_to(t_stack *src, t_stack *dst, bool print);
void	ss(t_stack *a, t_stack *b, bool print);
void	rr(t_stack *a, t_stack *b, bool print);
void	rrr(t_stack *a, t_stack *b, bool print);

///// Sorting Functions //////////////////////////////
//////////////////////////////////////////////////////
void	push_half(t_stack *a, t_stack *b);
int		is_sorted(int *array, int size);
int		is_sorted_circulary(int *array, int size);
int		find_min(int *array, int size);
int		find_max(int *array, int size);
int		sort_a_sorted_array(t_stack *s);
t_stack	*longest_sequence(t_stack s);
void	push_non_sequence(t_stack *src, t_stack *dst, t_stack seq);
int		calc_moves(int a_best, int b_best);
void	do_moves(t_stack *s, int moves);
int		nearest_number(t_stack s, int number);
void	sort_using_ls(t_stack *a, t_stack *b, int index, int min);
void	sort_small_number(t_stack *a, t_stack *b);
void	micro_sorting(t_stack *a);

///// Parsing And Checking Errors ////////////////////
//////////////////////////////////////////////////////
void	parse_check_error(t_stack *a, t_stack *b, char **args, int n_args);

///// Extra Utils ////////////////////////////////////
//////////////////////////////////////////////////////
void	print_err_exit(char *err, int err_len);
char	**dup_2d_strings_array(char **args, int n_elems);
int		max_int(int a, int b);
int		min_int(int a, int b);
int		absolute_value(int x);
char	*str_append(char *s1, char *s2);
void	free_pair(t_stack a, t_stack b);
void	free_single(t_stack *s);
void	free_parse(char **args, int n_elems);
int		limit_error(long long x);

///// Checker Utils ////////////////////////////////////
//////////////////////////////////////////////////////
char	*get_next_line(int fd);
int		move_exist(char *move);
void	move(int key, t_stack *a, t_stack *b);
int		testing_moves(char **moves, t_stack *a, t_stack *b);

#endif
