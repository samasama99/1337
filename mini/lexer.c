/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:19:52 by orahmoun          #+#    #+#             */
/*   Updated: 2022/02/17 00:07:55 by orahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

bool	check_unclosed_quotes_in_array(char **array)
{
	size_t	i;

	i = 0;
	if (array == NULL)
		return (NULL);
	while(array[i])
	{
		if (check_unclosed_quotes(array[i]))
			return (true);
		i++;
	}
	return (false);
}

char	**lexer(char *rl, int fd)
{
	char	**sp;
	char	**split_according;
	char	**res;
	char	*joined;
	size_t	i;

	i = 0;
	if (rl == NULL)
		return (NULL);
	if (check_unfulfilled_redirection(rl))
		return (NULL);
	sp = spilt_with_sp_ignoring_external_quotes(rl, ' ');
	res = init_2d_array();
	if(check_unclosed_quotes_in_array(sp))
	{
		free_2d_array(sp);
		write (fd, "ERROR : unclosed quotes\n", 25);
		return (NULL);
	}
	while (sp[i])
	{
		split_according = split_according_to_quotes(sp[i]);
		joined = join_2d_array_into_str(split_according);
		free_2d_array(split_according);
		split_according = NULL;
		res = add_element_2d_array_last(res, joined);
		i++;
	}
	free_2d_array(sp);
	return (res);
}

/* int main() */
/* { */
/* 	char		*rd; */
/* 	char		**sp; */
/* 	char		**parsed; */
/* 	char		**split_according; */
/* 	char		*joined; */
/* 	int			i; */

/* 	i = 0; */
/* 	parsed = init_2d_array(); */
/* 	while (1) */
/* 	{ */
/* 		rd = readline("> "); */
/* 		if (check_unclosed_quotes(rd) == true) */
/* 		{ */
/* 			free(rd); */
/* 			printf ("unclosed quotes\n"); */
/* 			continue ; */
/* 		} */
/* 		add_history(rd); */
/* 		sp = spilt_with_sp_ignoring_external_quotes(rd); */
/* 		while (sp[i]) */
/* 		{ */
/* 			split_according = split_according_to_quotes(sp[i]); */
/* 			joined = join_2d_array_into_str(split_according); */
/* 			free_2d_array(split_according); */
/* 			parsed = add_element_2d_array_last(parsed, */
/* 					joined); */
/* 			i++; */
/* 		} */
/* 		print_2d_array(parsed, 1); */
/* 		free_2d_array(sp); */
/* 		sp = NULL; */
/* 		free_2d_array(parsed); */
/* 		parsed = init_2d_array(); */
/* 		free(rd); */
/* 		rd = NULL; */
/* 		i = 0; */
/* 	} */
/* } */
