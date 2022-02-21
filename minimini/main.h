/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:49:06 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/18 16:50:01 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

/* #include "vector.h" */
/* #include "get_next_line/get_next_line.h" */
/* typedef t_vec t_sections; */
char	**ENV;

typedef struct s_section
{
	char *command;
	char **args;
	char *infile;
	char *outfile;
}				t_section;
/******* TOOLS ********/

t_list	*parse_input(char *input);
char	**init_2d_array(void);
void	print_2d_array(char **array, int fd);
char	*return_current_dir(void);
int		find_in_2d_array(char **array, char *str);
char	**dup_2d_array(char **array);
void	free_2d_array(char **array);
char	**add_element_2d_array(char **array, char *elem, size_t index);
char	**delete_element_2d_array(char **array, size_t index);
size_t	size_of_2d_array(char **array);
char	**add_element_2d_array_last(char **array, char *elem);
char	**join_2d_array(char **dst, char **source);
void	init_indexs(int amount, int value, ...);
char	*remove_str_in_str(char	*s, char *n);
char	*join_2d_array_into_str(char **array);
char	**split_and_join(char **array, char *line, char c);
int		skip_char(char *str, int *i, char c);
int		skip_until_char(char *str, int *i, char c);
char    *str_replace(char   *s, char *f, char *r);
char	*get_variable_env(char **env, char *variable);

/******* PARSING TOOLS *****/

char	*replace_variable_with_value(char **env, char *str);
bool	check_errors(char *rl);
char	**return_args_after_removing_quotes(char *rl);
char	**spilt_respecting_quotes(char *str, char c);
char	**scanner(char *rl);

/******* BUILTINS ********/

void	print_env(char **env, int fd);
int		find_in_env(char **env, char *variable);
void	pwd(int fd);
void	echo(char **args, int fd);
int		cd(char *path, char **env);
char	**ft_export(char **env, char *new_elem);
char	**ft_unset(char **env, char *variable);
#endif
