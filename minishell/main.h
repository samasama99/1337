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
typedef struct s_section
{
	char *command;
	char **args;
}				t_section;
/******* TOOLS ********/

int		ft_strcmp(const char *s1, const char *s2);
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
bool	check_unclosed_quotes(char *read_line);
void	init_indexs(int amount, int value, ...);
char	*remove_str_in_str(char	*s, char *n);

/******* BUILTINS ********/

void	print_env(char **env);
int		find_in_env(char **env, char *variable);
void	pwd(int fd);
void	echo(char **args, int fd);
int		cd(char *path, char **env);
char	**ft_export(char **env, char *new_elem);
char	**ft_unset(char **env, char *variable);
#endif
